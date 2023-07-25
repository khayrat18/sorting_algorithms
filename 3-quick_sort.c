#include "sort.h"

/**
 * swap - Swaps two integers.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Partitions an array using the Lomuto partition scheme.
 *
 * @arr: The array to partition.
 * @low: The lowest index of the subarray to partition.
 * @high: The highest index of the subarray to partition.
 *
 * Return: The index of the pivot element.
 */
int partition(int *arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1, j;
	int k;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				for (k = low; k <= high; k++)
				{
					printf("%d", arr[k]);
					if (k != high)
						printf(", ");
				}
				printf("\n");
			}
		}
	}
	if (arr[i + 1] != arr[high])
	{
		int k;

		swap(&arr[i + 1], &arr[high]);
		for (k = low; k <= high; k++)
		{
			printf("%d", arr[k]);
			if (k != high)
				printf(", ");
		}
		printf("\n");
	}
	return (i + 1);
}

/**
 * quicksort - Sorts an array using the Quick Sort algorithm.
 *
 * @arr: The array to sort.
 * @low: The lowest index of the subarray to sort.
 * @high: The highest index of the subarray to sort.
 */
void quicksort(int *arr, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(arr, low, high);

		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *             the Quick Sort algorithm.
 *
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1);
}
