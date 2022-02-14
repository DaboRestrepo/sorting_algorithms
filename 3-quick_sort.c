#include "sort.h"
/**
 * swap - Swap the elements.
 * @elem1: first element.
 * @elem2: second element.
 */
void swap(int *elem1, int *elem2)
{
	int temp = 0;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}
/**
 * partition - Separate the array in lowest and highiest.
 * @array: the giving array.
 * @low: the lowest index.
 * @high: the highiest index.
 * @first_size: the original array's size.
 * Return: the partition elemnt.
 */
int partition(int *array, int low, int high, size_t first_size)
{
	int pivot_value = array[high], i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_value)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, first_size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	if (i != j)
		print_array(array, first_size);
	return (i);
}
/**
 * quicksort_rec - Quicksort recursion.
 * @array: the giving array.
 * @low: the lowest index.
 * @high: the highiest index.
 * @first_size: the original array's size.
 */
void quicksort_rec(int *array, int low, int high, size_t first_size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, first_size);
		quicksort_rec(array, low, pivot - 1, first_size);
		quicksort_rec(array, pivot + 1, high, first_size);
	}
}
/**
 * quick_sort - Quicksort function.
 * @array: the giving array.
 * @size: the array's size.
 */
void quick_sort(int *array, size_t size)
{
	size_t first_size = size;

	if (size < 2)
		return;
	if (array)
		quicksort_rec(array, 0, size - 1, first_size);
}
