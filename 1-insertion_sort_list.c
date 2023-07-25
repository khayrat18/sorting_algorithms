#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: A pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;

		while (temp != NULL && temp->n > current->n)
		{
			temp->next->prev = temp->prev;

			if (temp->prev != NULL)
				temp->prev->next = temp->next;
			else
				*list = temp->next;

			temp->prev = temp->next;
			temp->next = temp->next->next;
			temp->prev->next = temp;

			if (temp->next != NULL)
				temp->next->prev = temp;

			print_list(*list);
			temp = current->prev;
		}

		current = current->next;
	}
}
