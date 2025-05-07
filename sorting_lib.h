#include "sorts.h"
#include "comps.h"
#include "prints.h"

int sort(void* array, int size, int elemsize, int(*comp)(void*a1,void*a2));

int sort(void* array, int size, int elemsize, int(*comp)(void*a1,void*a2)) {
    switch (SORT_METHOD)
    {
        case BUBBLE:
            print("Bubble sort", WHITE);
            bubble_sort(array, size, elemsize, comp);
            return 0;
        case INSERTION:
            print("Insertion sort", WHITE);
            insertion_sort(array, size, elemsize, comp);
            return 0;
        case SELECTION:
            print("Selection sort", WHITE);
            selection_sort(array, size, elemsize, comp);
            return 0;
        case COMB:
            print("Comb sort", WHITE);
            comb_sort(array, size, elemsize, comp);
            return 0;
        case SHELL:
            print("Shell sort", WHITE);
            shell_sort(array, size, elemsize, comp);
            return 0;
        case QUICK:
            print("Quick sort", WHITE);
            quick_sort(array, size, elemsize, comp, 0, size-1);
            return 0;
        case MERGE:
            print("Merge sort", WHITE);
            merge_sort(array, size, elemsize, comp, 0, size-1);
            return 0;
        case HEAP:
            print("Heap sort", WHITE);
            heap_sort(array, size, elemsize, comp);
            return 0;
        default:
            return 1;
    }
}