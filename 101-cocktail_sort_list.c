#include "sort.h"

/**
 * swap - function that swaps nodes in a linked
 * list of integers
 * @current_node: current position to swap
 * @next_node: next position to be swapped
 * @list: doubly linked list of integers
 * Return: void
 */
void swap(listint_t *current_node, listint_t *next_node, listint_t **list)
{
	/*mandamos el 99, mandamos el 71 y mandamos la cabeza 19*/
	/*el next del 99 apunta al 13*/
	current_node->next = next_node->next;
	/*el 13 existe ?*/
	if (current_node->next)
		/*el 13 prev apunta al 99*/
		current_node->next->prev = current_node;
	/*el 71 next apunta al 99*/
	next_node->next = current_node;
	/*el 71 prev apunta al 48*/
	next_node->prev = current_node->prev;
	/*el 48 existe ?*/
	if (next_node->prev)
		/*el 48 next apunta al 71*/
		next_node->prev->next = next_node;
	else
		*list = next_node;
	/*el 99 prev apunta al 71*/
	current_node->prev = next_node;

	print_list(*list);
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_node_ahead(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_node_behind(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
