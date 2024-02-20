#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - Sorts an array of integers in ascending order
 * using the Selection sort algorithm.
 * @array: pointer to the first element of the array to be sorted
 * @size: number of elements in the array
 *
 * Description: This function implements the Selection sort algorithm
 * to sort an array of integers in ascending order. After each swap,
 * the current state of the array is printed.
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    size_t min_idx;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
        {
            temp = array[i];
            array[i] = array[min_idx];
            array[min_idx] = temp;
            print_array(array, size); /* Function call to print the array */
        }
    }
}

