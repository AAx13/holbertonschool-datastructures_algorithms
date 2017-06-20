#include "search_algos.h"

/**
 * linear_search - searches for a value in an array of integers.
 * @array: Is a pointer to the first element of the array to search.
 * @size:  s the number of elements in array.
 * @value: Value is the value to search for.
 *
 * Return: Value compared or -1 if array or value doesn't exist.
 */
int linear_search(int *array, size_t size, int value)
{
	unsigned int i;

	if (!array)
	{
		return (-1);
	}

	for (i = 0; i < size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			return (value);
		}
	}
	return (-1);
}
