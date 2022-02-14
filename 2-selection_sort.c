#include "sort.h"
/**
 * selection_sort - Sort the array with selection sort method.
 * @array: array to be sorted.
 * @size: array size.
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min_i = 0;
	int temp = 0;

	if (array == NULL)
		return;

	if (size < 2)
		return;

	if (size > 0)
	{
		for (; i < size - 1; i++)
		{
			min_i = i;
			for (j = i + 1; j < size; j++)
			{
				if (array[j] < array[min_i])
					min_i = j;
			}
			temp = array[min_i];
			array[min_i] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
