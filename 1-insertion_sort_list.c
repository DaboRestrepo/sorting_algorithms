#include "sort.h"
/**
 * insertion_sort_list - Insertion sort method.
 * @list: the list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *temp1 = NULL, *temp2 = NULL;

	if (!list)
		return;
	current = *list;
	while ((current = current->next))
	{
		temp1 = current;
		while (temp1->prev && temp1->n < temp1->prev->n)
		{
			temp2 = temp1->prev;
			if (temp1->next)
				temp1->next->prev = temp2;
			if (temp2->prev)
				temp2->prev->next = temp1;
			else
				*list = temp1;
			temp2->next = temp1->next;
			temp1->prev = temp2->prev;
			temp1->next = temp2;
			temp2->prev = temp1;
			print_list(*list);
		}
	}
}
