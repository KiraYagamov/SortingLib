#include "sorts.h"
#include "comps.h"
#include "prints.h"

int sort(void* array, int size, int elemsize, int(*comp)(void*a1,void*a2));

int sort(void* array, int size, int elemsize, int(*comp)(void*a1,void*a2)) {
    switch (SORT_METHOD)
    {
        case 1:
            printf("Bubble sort\n");
            bubble_sort(array, size, elemsize, comp);
            return 0;
        case 2:
            printf("Insertion sort\n");
            insertion_sort(array, size, elemsize, comp);
            return 0;
        case 3:
            printf("Selection sort\n");
            selection_sort(array, size, elemsize, comp);
            return 0;
        case 4:
            printf("Comb sort\n");
            comb_sort(array, size, elemsize, comp);
            return 0;
        case 5:
            printf("Shell sort\n");
            shell_sort(array, size, elemsize, comp);
            return 0;
        case 6:
            printf("Quick sort\n");
            quick_sort(array, size, elemsize, comp, 0, size-1);
            return 0;
        case 7:
            printf("Merge sort\n");
            merge_sort(array, size, elemsize, comp, 0, size-1);
            return 0;
        case 8:
            printf("Heap sort\n");
            heap_sort(array, size, elemsize, comp);
            return 0;
        default:
            return 1;
    }
}