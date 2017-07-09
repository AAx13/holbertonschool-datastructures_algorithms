#include "search_algos.h"

int jump_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = sqrt(size);
	size_t i;

	if (array)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       left, array[left]);
		while (array[right] < value && right < size)
		{
			left = right;
			right += sqrt(size);
			printf("Value checked array[%lu] = [%d]\n",
			       left, array[left]);

			if (right > size - 1)
			{
				right = size;
			}
		}
		printf("Value found between indexes [%lu] and [%lu]\n",
		       left, right);

		for (i = left; i <= right && i < size; i++)
		{
			printf("Value checked array[%lu] = [%d]\n",
			       i, array[i]);
			if (array[i] == value)
			{
				return (value);
			}
		}
	}

	return (-1);
}
