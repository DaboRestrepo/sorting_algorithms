#include "sort.h"
/**
 * shell_sort - Shell sort method.
 * @array: array to be sorted.
 * @size: array's size.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 0, i = 0, j = 0;
	int elem = 0;

	while (interval < ((size - 1) / 9))
		interval = interval * 3 + 1;

	while (interval >= 1)
	{
		for (i = interval; i < size; i++)
		{
			elem = array[i];
			for (j = i - interval; elem < array[j]; j = j - interval)
				array[j + interval] = array[j];
			array[j + interval] = elem;
		}
		interval = interval / 3;
		print_array(array, size);
	}
}
