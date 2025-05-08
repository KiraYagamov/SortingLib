#ifndef SORTING_H
    #include "sorting_lib.h"
    #define SORTING_H
#endif
#include <time.h>

void test_int(int size) {
    print_long_line("Start test int", 40, YELLOW);
    for (int i = 0; i < 2; i++) {
        print_sort_direction();
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            int arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1;
            clock_t start = clock();
            sort(arr, size, sizeof(int), compInt);
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            check_sorted(arr, size, sizeof(int), compInt, seconds); 
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print_long_line("End test int", 40, YELLOW);
    printf("\n");
}

void test_float(int size) {
    print_long_line("Start test float", 40, YELLOW);
    for (int i = 0; i < 2; i++) {
        print_sort_direction();
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            float arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1 + (float) (rand() % 100) / 100;
            clock_t start = clock();
            sort(arr, size, sizeof(float), compFloat);
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            check_sorted(arr, size, sizeof(float), compFloat, seconds);
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print_long_line("End test float", 40, YELLOW);
    printf("\n");
}

void test_double(int size) {
    print_long_line("Start test double", 40, YELLOW);
    for (int i = 0; i < 2; i++) {
        print_sort_direction();
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            double arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1 + (float) (rand() % 100) / 100;
            clock_t start = clock();
            sort(arr, size, sizeof(double), compDouble);
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            check_sorted(arr, size, sizeof(double), compDouble, seconds);
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print_long_line("End test double", 40, YELLOW);
    printf("\n");
}

void test_long(int size) {
    print_long_line("Start test long", 40, YELLOW);
    for (int i = 0; i < 2; i++) {
        print_sort_direction();
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            long arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1;
            clock_t start = clock();
            sort(arr, size, sizeof(long), compLong);
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            check_sorted(arr, size, sizeof(long), compLong, seconds);
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print_long_line("End test long", 40, YELLOW);
    printf("\n");
}

void test_char(int size) {
    print_long_line("Start test char", 40, YELLOW);
    char symbols[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z'
    };
    for (int i = 0; i < 2; i++) {
        print_sort_direction();
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            char arr[size];
            for (int k = 0; k < size; k++)
                arr[k] = symbols[rand() % 26];
            clock_t start = clock();
            sort(arr, size, sizeof(char), compChar);
            clock_t end = clock();
            double seconds = (double)(end - start) / CLOCKS_PER_SEC;
            check_sorted(arr, size, sizeof(char), compChar, seconds);
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print_long_line("End test char", 40, YELLOW);
    printf("\n");
}
