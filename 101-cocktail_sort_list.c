#include "sort.h"
/**
 * swap - Swap the elements.
 * @left: current node.
 * @right: next node.
 */
void swap(listint_t *left, listint_t *right)
{
	listint_t *temp = NULL;

	temp = left->prev;
	if (temp)
		temp->next = right;
	right->prev = temp;

	left->prev = right;
	left->next = right->next;
	right->next = left;
	if (left->next)
		left->next->prev = left;
}
/**
 * cocktail_sort_list - Sort a list with the cocktail method.
 * @list: list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	int flag = 1;

	if (!list)
		return;
	while (flag == 1)
	{
		flag = 0;
		for (current = *list; current != NULL; current = current->next)
		{
			while (current->next && current->n > current->next->n)
			{
				swap(current, current->next);
				print_list(*list);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
		flag = 0;
		current = current->prev;
		for (current = current->prev; current != NULL; current = current->prev)
		{
			printf("%d\n", flag);
			while (current->prev && current->n < current->prev->n)
			{
				swap(current, current->prev);
				print_list(*list);
				flag = 1;
			}
		}
	}
}

