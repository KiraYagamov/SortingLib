#include "lib/sorting_lib.h"
#include "lib/tests.h"

int main() {
    // // int arr[] = {5, 7, 3, 4, 8, 0, 2, 1, 6};
    // char arr[] = {'b', 'g', 'v', 'n', 'm', 'y', 'a', 'c', 'd', 'e'};
    // int length = sizeof arr / sizeof arr[0];
    // sort(arr, length, sizeof arr[0], compChar);
    // print_char_arr(arr, length);
    test_char(10000);
    return 0;
}
