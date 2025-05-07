#ifndef SORTING_H
    #include "sorting_lib.h"
    #define SORTING_H
#endif

void test_int(int size) {
    print("Start test int", YELLOW);
    for (int i = 0; i < 2; i++) {
        print_sort_direction();
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            int arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1;
            // print_int_arr(arr, size);
            sort(arr, size, sizeof(int), compInt);
            // print_int_arr(arr,size);
            check_sorted(arr, size, sizeof(int), compInt); 
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print("End test int", YELLOW);
    printf("\n");
}

void test_float(int size) {
    print("Start test float", YELLOW);
    for (int i = 0; i < 2; i++) {
        print_sort_direction();
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            float arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1 + (float) (rand() % 100) / 100;
            // print_float_arr(arr, size);
            sort(arr, size, sizeof(float), compFloat);
            // print_float_arr(arr,size);
            check_sorted(arr, size, sizeof(float), compFloat);
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print("End test float", YELLOW);
    printf("\n");
}

void test_double(int size) {
    print("Start test double", YELLOW);
    for (int i = 0; i < 2; i++) {
        print_sort_direction();
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            double arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1 + (float) (rand() % 100) / 100;
            // print_double_arr(arr, size);
            sort(arr, size, sizeof(double), compDouble);
            // print_double_arr(arr,size);
            check_sorted(arr, size, sizeof(double), compDouble);
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print("End test double", YELLOW);
    printf("\n");
}

void test_long(int size) {
    print("Start test long", YELLOW);
    for (int i = 0; i < 2; i++) {
        print_sort_direction();
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            long arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1;
            // print_long_arr(arr, size);
            sort(arr, size, sizeof(long), compLong);
            // print_long_arr(arr,size);
            check_sorted(arr, size, sizeof(long), compLong);
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print("End test long", YELLOW);
    printf("\n");
}

void test_char(int size) {
    print("Start test char", YELLOW);
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
            // print_char_arr(arr, size);
            sort(arr, size, sizeof(char), compChar);
            // print_char_arr(arr,size);
            check_sorted(arr, size, sizeof(char), compChar);
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    print("End test char", YELLOW);
    printf("\n");
}
