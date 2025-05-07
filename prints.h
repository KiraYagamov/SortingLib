#include <stdio.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
#define GREEN   "\033[5;32m"

void print_int_arr(int* arr, int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

void print_float_arr(float* arr, int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        printf("%.2f, ", arr[i]);
    }
    printf("\n");
}

void print_char_arr(char* arr, int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        printf("%c, ", arr[i]);
    }
    printf("\n");
}

void print_double_arr(double* arr, int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        printf("%.2lf, ", arr[i]);
    }
    printf("\n");
}

void print_long_arr(long* arr, int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        printf("%ld, ", arr[i]);
    }
    printf("\n");
}

void print(char* str, char* color) {
    printf("%s%s%s", color, str, RESET);
    printf("\n");
}

void print_sort_direction() {
    print("----------------------------------------", RED);
    if (SORT_DIRECTION == INCREASE)
        printf("SORT_DIRECTION: INCREASE\n");
    else if (SORT_DIRECTION == DECREASE)
        printf("SORT_DIRECTION: DECREASE\n");
    else{
        printf("Error direction!");
        exit(1);
    }
    print("----------------------------------------", RED);
}

void check_sorted(void* arr, int size, int elemsize, int(*comp)(void*a1,void*a2)) {
    for (int i = 0; i < size-1; i++) {
        if (comp(arr + i * elemsize, arr + (i+1) * elemsize) == SORT_DIRECTION) {
            print("ТЕСТ НЕ ПРОЙДЕН!", RED);
            return;
        }
    }
    print("Тест пройден!", GREEN);
}