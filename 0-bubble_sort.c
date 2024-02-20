#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: pointer to the first element of the array to be sorted
 * @size: number of elements in the array
 *
 * Description: This function implements the Bubble sort algorithm
 * to sort an array of integers in ascending order. After each swap,
 * the current state of the array is printed.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
                print_array(array, size); /* Function call to print the array */
            }
        }
        /* If no two elements were swapped by inner loop, then break */
        if (swapped == 0)
            break;
    }
}

