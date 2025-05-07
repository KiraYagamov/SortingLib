#ifndef SORTING_H
    #include "sorting_lib.h"
    #define SORTING_H
#endif

void test_int() {
    printf("Start test int\n");
    for (int i = 0; i < 2; i++) {
        printf("SORT_DIRECTION: %d\n", SORT_DIRECTION);
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            int size = 7;
            int arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1;
            print_int_arr(arr, size);
            sort(arr, size, sizeof(int), compInt);
            print_int_arr(arr,size);
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test int\n\n");
}

void test_float() {
    printf("Start test float\n");
    for (int i = 0; i < 2; i++) {
        printf("SORT_DIRECTION: %d\n", SORT_DIRECTION);
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            int size = 7;
            float arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1 + (float) (rand() % 100) / 100;
            print_float_arr(arr, size);
            sort(arr, size, sizeof(float), compFloat);
            print_float_arr(arr,size);
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test float\n\n");
}

void test_double() {
    printf("Start test double\n");
    for (int i = 0; i < 2; i++) {
        printf("SORT_DIRECTION: %d\n", SORT_DIRECTION);
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            int size = 7;
            double arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1 + (float) (rand() % 100) / 100;
            print_double_arr(arr, size);
            sort(arr, size, sizeof(double), compDouble);
            print_double_arr(arr,size);
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test double\n\n");
}

void test_long() {
    printf("Start test long\n");
    for (int i = 0; i < 2; i++) {
        printf("SORT_DIRECTION: %d\n", SORT_DIRECTION);
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            int size = 7;
            long arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1;
            print_long_arr(arr, size);
            sort(arr, size, sizeof(long), compLong);
            print_long_arr(arr,size);
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test long\n\n");
}

void test_char() {
    printf("Start test char\n");
    char symbols[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z'
    };
    for (int i = 0; i < 2; i++) {
        printf("SORT_DIRECTION: %d\n", SORT_DIRECTION);
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            int size = 7;
            char arr[size];
            for (int k = 0; k < size; k++)
                arr[k] = symbols[rand() % 26];
            print_char_arr(arr, size);
            sort(arr, size, sizeof(char), compChar);
            print_char_arr(arr,size);
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test char\n\n");
}
