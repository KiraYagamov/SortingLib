#include <stdlib.h>
#include <stdio.h>
#include "consts.h"
#ifndef STRING_H
    #include <string.h>
    #define STRING_H
#endif

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    swap                                                               *
* DESCRIPTION                                                           *
*    Swaps the contents of two memory cells.                            *
* VARIABLES                                                             *
*    el1 - first memory cell                                            *
*    el2 - second memory cell                                           *
*    elemsize - size of the element of this array                       *
*                                                                       *
************************************************************************/

void swap(void* el1, void* el2, int elemsize) {
    char temp[elemsize];
    memcpy(temp, el1, elemsize);
    memcpy(el1, el2, elemsize);
    memcpy(el2, temp, elemsize);
}

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    bubble_sort                                                        *
* DESCRIPTION                                                           *
*    The bubble sort function sorts the array by comparing every two    *
*    adjacent elements and swapping them in case of a mismatch.         *
* VARIABLES                                                             *
*    arr - the array to sort                                            *
*    arr_size - size of this array                                      *
*    elemsize - size of the element of this array                       *
*    comp - function for comparing two elements of this array           *
*                                                                       *
************************************************************************/

void bubble_sort(void* arr, int arr_size, int elemsize, int(*comp)(void*a1,void*a2)) {
    int is_sorted = 0; // Флаг отсортированности
    while (!is_sorted) { // Пока массив не отсортирован мы его сортируем
        is_sorted = 1; // Меняем флаг на 1, после чего ищем опровержения
        for (int i = 0; i < arr_size-1; i++) {
            if (comp(arr + i * elemsize, arr + (i+1) * elemsize) == SORT_DIRECTION) { // Если элементы стоят не в том порядке
                swap(arr + i * elemsize, arr + (i+1) * elemsize, elemsize); // То меняем их местами
                is_sorted = 0; // И меняем флаг обратно на 0
            }
        }
    }
}

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    insertion_sort                                                     *
* DESCRIPTION                                                           *
*    The insertion sort function searches for an element that is out    *
*    of place and moves it to the most appropriate place among those    *
*    that it has already passed.                                        *
* VARIABLES                                                             *
*    arr - the array to sort                                            *
*    arr_size - size of this array                                      *
*    elemsize - size of the element of this array                       *
*    comp - function for comparing two elements of this array           *
*                                                                       *
************************************************************************/

void insertion_sort(void* arr, int arr_size, int elemsize, int(*comp)(void*a1,void*a2)) {
    for (int i = 1; i < arr_size; i++) { // Проходим все элементы
        int j = i - 1; // И создаем индексы для пар элементов i и j
        void* key = arr + i * elemsize; // Ключ - текущий перемещаемый элемент
        while (j >= 0 && comp(arr + j * elemsize, key) == SORT_DIRECTION) {
            // Меняем элементы местами до тех пор, пока не поставим ключ на место (тащим его в нужную позицию)
            swap(arr + j * elemsize, key, elemsize);
            key = arr + j * elemsize;
            j -= 1;
        }
    }
}

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    selection_sort                                                     *
* DESCRIPTION                                                           *
*    The selection sort finds the largest (or smallest) element and     *
*    puts it at the end, shifting the right border to the left. By      *
*    repeating this action, sorting takes place.                        *
* VARIABLES                                                             *
*    arr - the array to sort                                            *
*    arr_size - size of this array                                      *
*    elemsize - size of the element of this array                       *
*    comp - function for comparing two elements of this array           *
*                                                                       *
************************************************************************/

void selection_sort(void* arr, int arr_size, int elemsize, int(*comp)(void*a1,void*a2)) {
    int right = arr_size - 1; // Правая граница (в которую будем перемещать элементы)
    int current_index = 0; // Индекс наибольшего (или наименьшего) элемента
    for (int i = 0; i < arr_size; i++) {
        current_index = 0;
        // Находим наибольший (наименьший) элемент
        for (int j = 0; j <= right; j++)
            if (comp(arr + j * elemsize, arr + current_index * elemsize) == SORT_DIRECTION)
                current_index = j;
        // Ставим вправо наибольший (наименьший) элемент
        swap(arr + current_index * elemsize, arr + right * elemsize, elemsize);
        right -= 1; // Смещаем правую границу
    }
}

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    comb_sort                                                          *
* DESCRIPTION                                                           *
*    Comb sorting is an improved bubble sorting. it also compares two   *
*    elements, but with a dynamic distance between them. At first, the  *
*    distance is large, but after each pass it decreases until it       *
*    reaches the level of the usual bubble sorting.                     *
* VARIABLES                                                             *
*    arr - the array to sort                                            *
*    arr_size - size of this array                                      *
*    elemsize - size of the element of this array                       *
*    comp - function for comparing two elements of this array           *
*                                                                       *
************************************************************************/

void comb_sort(void* arr, int arr_size, int elemsize, int(*comp)(void*a1,void*a2)) {
    int step = arr_size / 1.247; // Вычисляем начальный шаг
    while (step != 1) { // Сортируем до тех пор, пока шаг не придет в состояние пузырька
        for (int i = 0; i < arr_size-1-step; i++)
             // Меняем элементы если стоят не в том порядке
            if (comp(arr + i * elemsize, arr + (i+step) * elemsize) == SORT_DIRECTION) 
                swap(arr + i * elemsize, arr + (i+step) * elemsize, elemsize);
        step /= 1.247; // Уменьшаем шаг
    }
    bubble_sort(arr, arr_size, elemsize, comp); // Когда дошли до шага 1 проводим обычный пузырек
}

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    shell_sort                                                         *
* DESCRIPTION                                                           *
*    Shell sorting is an improved insertion sort, which adds a step     *
*    that moves elements to their positions.                            *
* VARIABLES                                                             *
*    arr - the array to sort                                            *
*    arr_size - size of this array                                      *
*    elemsize - size of the element of this array                       *
*    comp - function for comparing two elements of this array           *
*                                                                       *
************************************************************************/

void shell_sort(void* arr, int arr_size, int elemsize, int(*comp)(void*a1,void*a2)) {
    for (int step = arr_size / 2; step > 0; step /= 2){ // Задаем шаг
        for (int i = step; i < arr_size; i++) { // Задаем индекс правого элемента
            int j = i - step; // Задаем индекс левого элемента
            void* key = arr + i * elemsize; // Задаем указатель на правый элемент
            // Перемещаем правый элемент на свое место
            while (j >= 0 && comp(arr + j * elemsize, key) == SORT_DIRECTION) {
                swap(arr + j * elemsize, key, elemsize);
                key = arr + j * elemsize;
                j -= step;
            }
        }
    }
}

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    quick_sort                                                         *
* DESCRIPTION                                                           *
*    Quick sort recursively divides an array into two parts: a subarray *
*    with elements larger than the reference and a subarray with        *
*    elements smaller than the reference. Then it puts them together,   *
*    creating a sorted array.                                           *
* VARIABLES                                                             *
*    arr - the array to sort                                            *
*    arr_size - size of this array                                      *
*    elemsize - size of the element of this array                       *
*    comp - function for comparing two elements of this array           *
*    left - left index of subarray                                      *
*    right - right index of subarray                                    *
*                                                                       *
************************************************************************/

void quick_sort(void* arr, int arr_size, int elemsize, int(*comp)(void*a1,void*a2), int left, int right) {
    if (left == right) return; // Если подмассив состоит из 1 элемента -> ничего делать не надо
    char pivot[elemsize]; // Создаем опорный элемент
    int index; // Индекс опорного элемента
    int l_hold = left; // Запоминаем изначальные значения левой и правой границы
    int r_hold = right;
    memcpy(pivot, arr + left * elemsize, elemsize); // Копируем биты в опорный элемент
    while (left < right) { // Пока границы не сошлись
        // Ищем справа элемент, который должен стоять слева
        while ((comp(arr + right * elemsize, pivot)) == SORT_DIRECTION && (left < right))
            right--;
        if (left != right) { // Если границы не сошлись заменяем место опорного элемента на найденный элемент
            memcpy(arr + left * elemsize, arr + right * elemsize, elemsize);
            left++; // Сдвигаем место опорного элемента
        }
        // Ищем слева элементы, которые стоят не на своем месте
        while ((comp(arr + left * elemsize, pivot)) == -SORT_DIRECTION && (left < right))
            left++;
        // Если границы не сошлись, то меняем местами элементы на левой и правой границах, смещая правую границу влево
        if (left != right) {
            memcpy(arr + right * elemsize, arr + left * elemsize, elemsize);
            right--;
        }
    }
    // Ставим опорный элемент на свое место
    memcpy(arr + left * elemsize, pivot, elemsize);
    index = left; // Устанавливаем индекс опорного элемента
    left = l_hold; // Возвращаем значения, которые запомнили в начале
    right = r_hold;
    if (left < index) // Если опорный элемент не крайний, то рекурсивно обрабатываем подмассив элементов, меньших чем опорный
        quick_sort(arr, arr_size, elemsize, comp, left, index - 1);
    if (right > index)// Если опорный элемент не крайний, то рекурсивно обрабатываем подмассив элементов, больших чем опорный
        quick_sort(arr, arr_size, elemsize, comp, index + 1, right);
}

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    merge_sort                                                         *
* DESCRIPTION                                                           *
*    Merge sort recursively divides the array in half until it reaches  *
*    subarrays of a single element, after which it merges the resulting *
*    subarrays in sorted order.                                         *
* VARIABLES                                                             *
*    arr - the array to sort                                            *
*    arr_size - size of this array                                      *
*    elemsize - size of the element of this array                       *
*    comp - function for comparing two elements of this array           *
*    left - left index of subarray                                      *
*    right - right index of subarray                                    *
*                                                                       *
************************************************************************/

void merge_sort(void* arr, int arr_size, int elemsize, int(*comp)(void*a1,void*a2), int left, int right)
{
    if (left == right) return; // Если подмассив состоит из одного элемента -> ничего делать не надо
    int mid = (left + right) / 2; // Ищем место разделения
    merge_sort(arr, arr_size, elemsize, comp, left, mid); // Сортируем левую половину массива
    merge_sort(arr, arr_size, elemsize, comp, mid + 1, right); // Сортируем правую половину массива
    int i = left; // Начальный индекс в левом подмассиве
    int j = mid + 1; // Начальный индекс в правом подмассиве
    char tmp[arr_size * elemsize]; // Создаем буффер для сохранения отсортированной части массива
    // Сливаем два отсортированных подмассива в один отсортированный массив
    for (int step = 0; step < right - left + 1; step++) { // Задаем шаг (индекс массива буффера)
        // Если элемент левой половины оказался меньше (или больше), то ставим его на этом шаге
        if (j > right || 
            (i <= mid && comp(arr + i * elemsize, arr + j * elemsize) == -SORT_DIRECTION)) { 
            memcpy(tmp + step * elemsize, arr + i * elemsize, elemsize);
            i++;
        }
        // Если же элемент правой половины оказался меньше (или больше), то ставим уже его
        else {
            memcpy(tmp + step * elemsize, arr + j * elemsize, elemsize);
            j++;
        }
    }
    // Переносим данные из буффера в оригинальный массив
    for (int step = 0; step < right - left + 1; step++)
        memcpy(arr + (left + step) * elemsize, tmp + step * elemsize, elemsize);
}

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    heapify                                                            *
* DESCRIPTION                                                           *
*    The heapify function rearranges the elements in the array so that  *
*    a binary heap is formed in which the ancestor is greater than the  *
*    descendants.                                                       *
* VARIABLES                                                             *
*    arr - the array to sort                                            *
*    length - size of this array                                        *
*    i - index of checking parent                                       *
*    elemsize - size of the element of this array                       *
*    comp - function for comparing two elements of this array           *
*                                                                       *
************************************************************************/

void heapify(void* arr, int length, int i, int elemsize, int(*comp)(void*a1,void*a2))
{
    int largest = i; // Инициализируем наибольший (или наименьший) элемент как корень
    int left = 2*i + 1; // левый = 2*i + 1
    int right = 2*i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше (или меньше) корня
    if (left < length && comp(arr + left * elemsize, arr + largest * elemsize) == SORT_DIRECTION)
        largest = left;

    // Если правый дочерний элемент больше (или меньше), чем наибольший (или наименьший) элемент на данный момент
    if (right < length && comp(arr + right * elemsize, arr + largest * elemsize) == SORT_DIRECTION)
        largest = right;

    // Если наибольший (или наименьший) элемент не корень
    if (largest != i) {
        swap(arr + i * elemsize, arr + largest * elemsize, elemsize);
        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, length, largest, elemsize, comp);
    }
}

/************************************************************************
*                                                                       *
* NAME                                                                  *
*    heap_sort                                                          *
* DESCRIPTION                                                           *
*    Heap sorting makes up a binary heap in which each parent is at     *
*    least as large as its descendants, after which the root of the     *
*    tree is moved to the end, and the processed part of the array is   *
*    reduced by one.                                                    *
* VARIABLES                                                             *
*    arr - the array to sort                                            *
*    arr_size - size of this array                                      *
*    elemsize - size of the element of this array                       *
*    comp - function for comparing two elements of this array           *
*                                                                       *
************************************************************************/

void heap_sort(void* arr, int arr_size, int elemsize, int(*comp)(void*a1,void*a2))
{
    // Построение кучи (перегруппируем массив)
    for (int i = arr_size / 2 - 1; i >= 0; i--)
        heapify(arr, arr_size, i, elemsize, comp);
    // Один за другим извлекаем элементы из кучи
    for (int i = arr_size - 1; i >= 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr + 0 * elemsize, arr + i * elemsize, elemsize);
        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0, elemsize, comp);
    }
}
