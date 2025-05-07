#include <stdio.h>

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