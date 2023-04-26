#include "sort.h"

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shaker: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}
/**
 * cocktail_sort_list - function that sorts a doubly linked
 * list of integers in ascending order using the Cocktail
 * shaker sort algorithm
 * @list: doubly linked list of integers
 * Description: Krofah
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *front_runner, *back_runner;
	int swapped = 1;

	if (list == NULL || *list == NULL)
		return;
	front_runner = (*list);
	back_runner = NULL;
	while (swapped == 1)
	{
		/*Here we are going forward*/
		swapped = 0;
		/*19, 48, 99, 71, 13, 52, 96, 73, 86, 7*/
		while (front_runner->next && front_runner != back_runner)
		{
			/*99 es mayor que 71 ?*/
			if (front_runner->n > front_runner->next->n)
			{
				swapped = 1;/*mandamos el 99, el 71 y la cabeza 19*/
				swap(front_runner, front_runner->next, list);
			}
			else
				front_runner = front_runner->next;
		}
		back_runner = front_runner;
		if (swapped == 0)
			break;
		/*Here we are going backward*/
		swapped = 0;
		while (front_runner->prev && front_runner != *list)
		{
			if (front_runner->n < front_runner->prev->n)
			{
				swapped = 1;
				swap(front_runner->prev, front_runner, list);
			}
			else
				front_runner = front_runner->prev;
		}
		*list = front_runner;
	}
}
