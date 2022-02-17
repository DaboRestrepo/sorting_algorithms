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
	current = *list;
	while (flag == 1)
	{
		flag = 0;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap(current, current->next);
				print_list(*list);
				flag = 1;
			}
			else
				current = current->next;
		}
		if (flag == 0)
			break;
		flag = 0;
		while (current->prev != NULL)
		{
			if (current->prev->n > current->n)
			{
				swap(current->prev, current);
				print_list(*list);
				flag = 1;
			}
			else
				current = current->prev;
		}
	}
}
