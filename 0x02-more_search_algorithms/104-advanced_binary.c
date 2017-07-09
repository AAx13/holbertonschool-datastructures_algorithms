#include "search_algos.h"

/**
 * advanced_binary - searches for a value in an array of integers.
 * return the index of the first value in the array
 * (if this value appears more than once in the array).
 * @array: Is a pointer to the first element of the array to search.
 * @size:  s the number of elements in array.
 * @value: Value is the value to search for.
 *
 * Return: Index where value exists or -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t mid, left, right, print;

	left = 0;
	right = size - 1;
	if (array && size != 0)
	{
		do {
			mid = left + (right - left) / 2;
			printf("Searching in array: ");
			print = left;
			while (print <= right)
			{
				if (print == right)
				{
					printf("%d\n", array[print]);
				}
				else
				{
					printf("%d, ", array[print]);
				}
				print++;
			}

			if (value == array[mid] && array[mid - 1] != value)
				return (mid);

			if (value > array[mid])
				left = mid + 1;

			if (value <= array[mid])
				right = mid;

		} while (left <= right);
	}

	return (-1);
}
