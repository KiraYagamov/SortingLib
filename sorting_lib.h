#include "sorts.h"
#include "comps.h"
#include "prints.h"

int sort(void* array, int size, int elemsize, int(*comp)(void*a1,void*a2));

int sort(void* array, int size, int elemsize, int(*comp)(void*a1,void*a2)) {
    switch (SORT_METHOD)
    {
        case BUBBLE:
            printf("Bubble sort: ");
            bubble_sort(array, size, elemsize, comp);
            return 0;
        case INSERTION:
            printf("Insertion sort: ");
            insertion_sort(array, size, elemsize, comp);
            return 0;
        case SELECTION:
            printf("Selection sort: ");
            selection_sort(array, size, elemsize, comp);
            return 0;
        case COMB:
            printf("Comb sort: ");
            comb_sort(array, size, elemsize, comp);
            return 0;
        case SHELL:
            printf("Shell sort: ");
            shell_sort(array, size, elemsize, comp);
            return 0;
        case QUICK:
            printf("Quick sort: ");
            quick_sort(array, size, elemsize, comp, 0, size-1);
            return 0;
        case MERGE:
            printf("Merge sort: ");
            merge_sort(array, size, elemsize, comp, 0, size-1);
            return 0;
        case HEAP:
            printf("Heap sort: ");
            heap_sort(array, size, elemsize, comp);
            return 0;
        default:
            return 1;
    }
}