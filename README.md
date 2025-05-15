**Sorting Library**
===========

***SORTING LIB***
===========
NAME
--------

**sort** — Sorts the array according to the selected sorting method

DESCRIPTION
--------

Sorts the array according to the selected sorting method. The possible sorting methods are numbered from 1 to 8:

1. Bubble sort
2. Insertion sort
3. Selection sort
4. Comb sort
5. Shell sort
6. Quicksort
7. Merge sort
8. Heap sort

Possible options are listed in the consts.h file.
To change the sorting method, it is enough to change the SORT_METHOD variable.

HOW TO USE IT
--------
Include the file sorting_lib.h from lib/ like this:
```C
#include "lib/sorting_lib.h"
```
And use function sort like this:
```C
int arr[] = {5, 7, 3, 4, 8, 0, 2, 1, 6};
int length = sizeof arr / sizeof arr[0];
sort(arr, length, sizeof arr[0], compInt);
print_int_arr(arr, length);
```
***TESTS***
===========
NAME
--------

**test_\<type>** — Performs tests of all types of sorting for a given data type, both ascending and descending.

DESCRIPTION
--------

Performs tests of all types of sorting for a given data type, both ascending and descending.

Supported types:

1. int
2. float
3. double
4. long
5. char

These functions also take a parameter, the size of the array under test.

HOW TO USE IT
--------
Include files sorting_lib.h and tests.h from lib/ like this:
```C
#include "lib/sorting_lib.h"
#include "lib/tests.h"
```
And start tests like this:
```C
test_int(10000);
```
