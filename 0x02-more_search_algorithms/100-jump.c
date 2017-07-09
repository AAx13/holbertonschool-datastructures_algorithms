#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm.
 * @array: An array to search.
 * @size: Size of the array.
 * @value: Value to search for.
 *
 * Return: Index to value location or -1 if does not exist.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = sqrt(size);

	if (array && size)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       left, array[left]);
		while (array[right] < value && right < size)
		{
			left = right;
			right += sqrt(size);
			printf("Value checked array[%lu] = [%d]\n",
			       left, array[left]);

		}
		printf("Value found between indexes [%lu] and [%lu]\n",
		       left, right);

		while (left <= right && left < size)
		{
			printf("Value checked array[%lu] = [%d]\n",
			       left, array[left]);
			if (array[left] == value)
			{
				return (left);
			}
			left++;
		}
	}

	return (-1);
}
