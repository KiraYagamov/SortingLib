#include "sorts.h"
#include "comps.h"
#include "prints.h"

int sort(void* array, int size, int elemsize, int(*comp)(void*a1,void*a2));

int sort(void* array, int size, int elemsize, int(*comp)(void*a1,void*a2)) {
    if (SORT_DIRECTION >= 0) SORT_DIRECTION = 1;
    else SORT_DIRECTION = -1;
    switch (SORT_METHOD)
    {
        case BUBBLE:
            if (TEST) printf("Bubble sort: ");
            bubble_sort(array, size, elemsize, comp);
            return 0;
        case INSERTION:
            if (TEST) printf("Insertion sort: ");
            insertion_sort(array, size, elemsize, comp);
            return 0;
        case SELECTION:
            if (TEST) printf("Selection sort: ");
            selection_sort(array, size, elemsize, comp);
            return 0;
        case COMB:
            if (TEST) printf("Comb sort: ");
            comb_sort(array, size, elemsize, comp);
            return 0;
        case SHELL:
            if (TEST) printf("Shell sort: ");
            shell_sort(array, size, elemsize, comp);
            return 0;
        case QUICK:
            if (TEST) printf("Quick sort: ");
            quick_sort(array, size, elemsize, comp, 0, size-1);
            return 0;
        case MERGE:
            if (TEST) printf("Merge sort: ");
            merge_sort(array, size, elemsize, comp, 0, size-1);
            return 0;
        case HEAP:
            if (TEST) printf("Heap sort: ");
            heap_sort(array, size, elemsize, comp);
            return 0;
        default:
            print_long_line("FAIL TO SORT!", 40, RED);
            exit(1);
    }
}