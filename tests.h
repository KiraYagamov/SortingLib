#ifndef SORTING_H
    #include "sorting_lib.h"
    #define SORTING_H
#endif

int check_sorted(void* arr, int size, int elemsize, int(*comp)(void*a1,void*a2)) {
    for (int i = 0; i < size-1; i++) {
        if (comp(arr + i * elemsize, arr + (i+1) * elemsize) == SORT_DIRECTION) 
            return 0;
    }
    return 1;
}

void test_int(int size) {
    printf("Start test int\n");
    for (int i = 0; i < 2; i++) {
        if (SORT_DIRECTION == INCREASE)
            printf("SORT_DIRECTION: INCREASE\n");
        else if (SORT_DIRECTION == DECREASE)
            printf("SORT_DIRECTION: DECREASE\n");
        else{
            printf("Error direction!");
            exit(1);
        }
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            int arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1;
            // print_int_arr(arr, size);
            sort(arr, size, sizeof(int), compInt);
            // print_int_arr(arr,size);
            if (check_sorted(arr, size, sizeof(int), compInt)) 
                printf("Тест пройден!");
            else
                printf("ТЕСТ НЕ ПРОЙДЕН!");
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test int\n\n");
}

void test_float(int size) {
    printf("Start test float\n");
    for (int i = 0; i < 2; i++) {
        if (SORT_DIRECTION == INCREASE)
            printf("SORT_DIRECTION: INCREASE\n");
        else if (SORT_DIRECTION == DECREASE)
            printf("SORT_DIRECTION: DECREASE\n");
        else{
            printf("Error direction!");
            exit(1);
        }
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            float arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1 + (float) (rand() % 100) / 100;
            // print_float_arr(arr, size);
            sort(arr, size, sizeof(float), compFloat);
            // print_float_arr(arr,size);
            if (check_sorted(arr, size, sizeof(float), compFloat)) 
                printf("Тест пройден!");
            else
                printf("Тест не пройден!");
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test float\n\n");
}

void test_double(int size) {
    printf("Start test double\n");
    for (int i = 0; i < 2; i++) {
        if (SORT_DIRECTION == INCREASE)
            printf("SORT_DIRECTION: INCREASE\n");
        else if (SORT_DIRECTION == DECREASE)
            printf("SORT_DIRECTION: DECREASE\n");
        else{
            printf("Error direction!");
            exit(1);
        }
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            double arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1 + (float) (rand() % 100) / 100;
            // print_double_arr(arr, size);
            sort(arr, size, sizeof(double), compDouble);
            // print_double_arr(arr,size);
            if (check_sorted(arr, size, sizeof(double), compDouble)) 
                printf("Тест пройден!");
            else
                printf("Тест не пройден!");
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test double\n\n");
}

void test_long(int size) {
    printf("Start test long\n");
    for (int i = 0; i < 2; i++) {
        if (SORT_DIRECTION == INCREASE)
            printf("SORT_DIRECTION: INCREASE\n");
        else if (SORT_DIRECTION == DECREASE)
            printf("SORT_DIRECTION: DECREASE\n");
        else{
            printf("Error direction!");
            exit(1);
        }
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            long arr[size];
            for (int k = 0; k < size; k++) 
                arr[k] = rand() % size + 1;
            // print_long_arr(arr, size);
            sort(arr, size, sizeof(long), compLong);
            // print_long_arr(arr,size);
            if (check_sorted(arr, size, sizeof(long), compLong)) 
                printf("Тест пройден!");
            else
                printf("Тест не пройден!");
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test long\n\n");
}

void test_char(int size) {
    printf("Start test char\n");
    char symbols[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g',
        'h', 'i', 'j', 'k', 'l', 'm', 'n',
        'o', 'p', 'q', 'r', 's', 't', 'u',
        'v', 'w', 'x', 'y', 'z'
    };
    for (int i = 0; i < 2; i++) {
        if (SORT_DIRECTION == INCREASE)
            printf("SORT_DIRECTION: INCREASE\n");
        else if (SORT_DIRECTION == DECREASE)
            printf("SORT_DIRECTION: DECREASE\n");
        else{
            printf("Error direction!");
            exit(1);
        }
        for (int j = 1; j <= 8; j++) {
            SORT_METHOD = j;
            char arr[size];
            for (int k = 0; k < size; k++)
                arr[k] = symbols[rand() % 26];
            // print_char_arr(arr, size);
            sort(arr, size, sizeof(char), compChar);
            // print_char_arr(arr,size);
            if (check_sorted(arr, size, sizeof(char), compChar)) 
                printf("Тест пройден!");
            else
                printf("Тест не пройден!");
            printf("\n");
        }
        SORT_DIRECTION = -SORT_DIRECTION;
    }
    printf("End test char\n\n");
}
