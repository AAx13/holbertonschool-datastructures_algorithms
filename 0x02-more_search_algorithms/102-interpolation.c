#include "search_algos.h"

/**
 * get_pos - returns position to start searching
 * based on interpolation formula.
 * @array: An array to search.
 * @high: Last index of the array.
 * @low: First index of the array.
 * @value: Value to search for.
 *
 * Return: position to start search from.
 */
size_t get_pos(int *array, size_t high, size_t low, int value)
{
	size_t pos;

	pos = low + (((double)(high - low)
		  / (array[high] - array[low]))
		  * (value - array[low]));

	return (pos);
}

/**
 * interpolation_search - searches for a value in a sorted
 * array of integers using the Interpolation search algorithm.
 * based on interpolation formula.
 * @array: An array to search.
 * @size: Size of the array.
 * @value: Value to search for.
 *
 * Return: Index containing the value requested or -1 if non existant.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t lo = 0, hi = size - 1;
	size_t pos;

	if (!array || size == 0)
	{
		return (-1);
	}

	do {
		pos = get_pos(array, hi, lo, value);
		if (pos > size - 1)
		{
			printf("Value checked array[%lu] is out of range\n",
			       pos);
			return (-1);
		}
		else
		{
			printf("Value checked array[%lu] = [%d]\n",
			       pos, array[pos]);
		}

		if (array[pos] == value)
		{
			return (pos);
		}

		if (value > array[pos])
		{
			lo = pos + 1;
		}

		if (value < array[pos])
		{
			hi = pos - 1;
		}

	} while (lo <= hi && value >= array[lo] && value <= array[hi]);

	return (-1);
}
