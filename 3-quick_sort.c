#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - Swap two integers in an array.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * Description: This function swaps the values of two integers
 *              pointed to by 'a' and 'b'.
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * lomuto_partition - Partition a subset of an array of integers using the Lomuto scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 *
 * Return: The final partition index.
 *
 * Description: This function partitions a subset of the array
 *              using the Lomuto partition scheme, with the last
 *              element as the pivot. It rearranges the elements
 *              in the subset such that all elements less than the
 *              pivot are placed before it, and all elements greater
 *              than or equal to the pivot are placed after it. The
 *              function returns the final position of the pivot.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
    int *pivot = array + right;
    int above = left;
    int below;

    for (below = left; below < right; below++)
    {
        if (array[below] < *pivot)
        {
            if (above != below)
            {
                swap_ints(array + above, array + below);
                print_array(array, size);
            }
            above++;
        }
    }

    if (array[above] > *pivot)
    {
        swap_ints(array + above, pivot);
        print_array(array, size);
    }

    return above;
}

/**
 * lomuto_sort - Sort an array of integers using the Lomuto scheme.
 * @array: An array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 *
 * Description: This function recursively sorts a subset of the array
 *              using the Lomuto partition scheme. It partitions the
 *              array into two parts around a pivot, and then recursively
 *              sorts the two partitions.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
    int part;

    if (right - left > 0)
    {
        part = lomuto_partition(array, size, left, right);
        lomuto_sort(array, size, left, part - 1);
        lomuto_sort(array, size, part + 1, right);
    }
}

/**
 * quick_sort - Sort an array of integers using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 *              using the quicksort algorithm with the Lomuto partition scheme.
 *              It recursively partitions the array into smaller subarrays
 *              and sorts them separately. It prints the array after each swap
 *              operation.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}

