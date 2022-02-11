#include "sort.h"
/**
 * bubble_sort - Sort the array with bubble sort method.
 * @array: array to be sorted.
 * @size: size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp = 0;

	if (size == 1)
		return;

	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			print_array(array, size);
		}
		bubble_sort(array, size - 1);
	}
	else
		return;
}
