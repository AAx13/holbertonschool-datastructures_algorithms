#include "search_algos.h"

/**
 * binary_search - searches for a value in an array of integers.
 * @array: Is a pointer to the first element of the array to search.
 * @size:  s the number of elements in array.
 * @value: Value is the value to search for.
 *
 * Return: Value compared or -1 if array or value doesn't exist.
 */
int binary_search(int *array, size_t size, int value)
{
	unsigned int l, m, r;

	l = 0;
	r = size;
	while (l <= r)
	{
		m = l + (r - l) / 2;

		if (value == array[m])
		{
			return (m);
		}

		if (value < array[m])
		{
			r = m - 1;
		}

		if (value > array[m])
		{
			l = m + 1;
		}
	}
	return (-1);
}
