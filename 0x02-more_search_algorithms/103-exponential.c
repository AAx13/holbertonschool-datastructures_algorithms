#include "search_algos.h"

/**
 * binary_search - searches for a value in an array of integers.
 * @array: Is a pointer to the first element of the array to search.
 * @left: Left limit of array.
 * @right: Right limit of the array.
 * @value: Value to search for.
 *
 * Return: Value compared or -1 if array or value doesn't exist.
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid, print;

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

		if (value == array[mid])
		{
			return (mid);
		}

		if (value > array[mid])
		{
			left = mid + 1;
		}

		if (value < array[mid])
		{
			right = mid;
		}

	} while (left <= right);

	return (-1);
}

/**
 * exponential_search - searches for a value in a sorted
 * array of integers using the Exponential search algorithm.
 * @array: An array to search.
 * @size: Size of the array.
 * @value: Value to search for.
 *
 * Return: Index where value is located or -1 if does not exist.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t left, right;

	if (!array || size == 0)
	{
		return (-1);
	}

	left = 0;
	right = size;

	while (left < right && array[left] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", left, array[left]);
		if (left == 0)
		{
			left++;
		}
		left *= 2;
	}
	right = left;
	left = left / 2;

	if (right >= size)
	{
		right--;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", left, right);

	return (binary_search(array, left, right, value));
}
