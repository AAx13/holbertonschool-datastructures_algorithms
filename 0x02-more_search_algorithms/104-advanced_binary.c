#include "search_algos.h"

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
			if (left == right && array[left] != value)
				return (-1);

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
