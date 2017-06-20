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
	unsigned int l, m, r, p;

	l = 0;
	r = size - 1;
	while (l <= r)
	{
		m = l + (r - l) / 2;
		p = l;
		printf("Searching in array: ");
		while (p <= r)
		{
			if (p == r)
			{
				printf("%d\n", array[p]);
			}
			else
			{
				printf("%d, ", array[p]);
			}
			p++;
		}
		if (value == array[m])
		{
			return (m);
		}

		if (value > array[m])
		{
			l = m + 1;
		}

		if (value < array[m])
		{
			r = m;
		}
	}
	return (-1);
}
