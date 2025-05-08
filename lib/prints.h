#include <stdio.h>
#ifndef STRING_H
    #include <string.h>
    #define STRING_H
#endif

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define WHITE   "\033[1;37m"
#define GREEN   "\033[1;32m"

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
}

void println(char* str, char* color) {
    print(str, color);
    printf("\n");
}

void print_long_line(char* data, int length_of_line, char* color) {
    char result[length_of_line+1];
    int length = strlen(data);
    int pos = (length_of_line - length) / 2;
    int length_of_spaces = pos;
    for (int i = 0; i < length_of_spaces; i++) result[i] = '-';
    for (int i = 0; i < length; i++) result[length_of_spaces + i] = data[i];
    for (int i = 0; i < length_of_spaces + length % 2; i++) result[length_of_spaces + length + i] = '-';
    result[length_of_line] = 0;
    println(result, color);
}

void check_sorted(void* arr, int size, int elemsize, int(*comp)(void*a1,void*a2), double time) {
    char timeStr[10];
    snprintf(timeStr, sizeof timeStr, "%lf", time);
    char result[20];
    for (int i = 0; i < size-1; i++) {
        if (comp(arr + i * elemsize, arr + (i+1) * elemsize) == SORT_DIRECTION) {
            println("FAIL!", RED);
            return;
        }
    }
    print("SUCCESS! ", GREEN);
    printf("Time: %.2lfs\n", time);
}

void print_sort_direction() {
    switch (SORT_DIRECTION){
        case INCREASE:
            print_long_line("SORT_DIRECTION: INCREASE", 40, WHITE);
            break;
        case DECREASE:
            print_long_line("SORT_DIRECTION: DECREASE", 40, WHITE);
            break;
        default:
            print_long_line("Error direction!", 40, RED);
            exit(1);
    }
}
