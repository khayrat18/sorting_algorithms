#include "sort.h"

/**
 * swap_elements - swaps two elelments
 * @a: element to be swapped
 * @b: element to be swapped
*/

void swap_elements(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/**
 * partition_function - 
 * @array: array to be checked
 * @low:
 * @high:
*/
int partition_function(int *array, int low, int high) 
{
    int j;
    int pivot = array[high];
    int i = low - 1;
    for (j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap_elements(&array[i], &array[j]);
        }
    }
    swap_elements(&array[i+1], &array[high]);
    return i+1;
}
/**
 * quick_sort_helper
*/
void quick_sort_helper(int *array, int low, int high) 
{
    int i;

    if (low < high) {
        int p = partition_function(array, low, high);
        for (i = low; i <= high; i++) {
            printf("%d", array[i]);
            if (i < high) {
                printf(", ");
            }
        }
        printf("\n");
        quick_sort_helper(array, low, p-1);
        quick_sort_helper(array, p+1, high);
    }
}
/**
 * quick_sort
*/
void quick_sort(int *array, size_t size) {
    quick_sort_helper(array, 0, size-1);
}

    

           
   
