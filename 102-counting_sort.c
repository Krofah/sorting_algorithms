#include "sort.h"

/**
 * _bigest -  Give me the largest number in a array of integers
 * @a: The Int array
 * @size: Size of array
 * Return: The maximum integer in the array
 */
int _bigest(int *a, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < a[i])
			k = a[i];
	}
	return (k);
}
/**
 * _memset -  Create a integer array and set each space in 0
 * @size: Size of array
 * Return: The integer array
 */
int *_memset(int size)
{
	int *ptr = NULL;
	int i;

	ptr = malloc((size) * sizeof(int));

	for (i = 0; i < size; i++)
		ptr[i] = 0;

	return (ptr);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, i;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
