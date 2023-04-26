#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
  * insertion_sort_list - Sorts an doubly linked list
  * of integers in ascending order using
  * the Insertion sort algorithm.
  * @list: The doubly linked list to sort
  *
  * Description: Krofah Project
  */
void insertion_sort_list(listint_t **list)
{
	bool flag = false;
	listint_t *tmp = NULL, *aux = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->n > tmp->next->n)
		{
			tmp->next->prev = tmp->prev;
			if (tmp->next->prev)
				tmp->prev->next = tmp->next;
			else
				*list = tmp->next;

			tmp->prev = tmp->next;
			tmp->next = tmp->next->next;
			tmp->prev->next = tmp;
			if (tmp->next)
				tmp->next->prev = tmp;

			tmp = tmp->prev;
			print_list(*list);

			if (tmp->prev && tmp->prev->n > tmp->n)
			{
				if (!flag)
					aux = tmp->next;
				flag = true;
				tmp = tmp->prev;
				continue;
			}
		}
		if (!flag)
			tmp = tmp->next;
		else
			tmp = aux, flag = false;
	}
}

