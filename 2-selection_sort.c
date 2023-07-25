#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array of integers
 * @size: sizee of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, min;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;


		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;

		for (k = 0; k < size; k++)
		{
			printf("%d", array[k]);
			if (k < size - 1)
				printf(", ");

		}
		printf("\n");
	}

}
