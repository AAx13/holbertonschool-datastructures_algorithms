#include "heap.h"

/**
 * heap_create - creates a Heap data structure.
 * @data_cmp: Pointer to a comparison function.
 *
 * Return: Pointer to a Heap data strcuture or NULL if failed.
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *heap = NULL;

	heap = malloc(sizeof(heap_t));
	if (!heap)
	{
		return (NULL);
	}

	heap->size = 0;
	heap->data_cmp = data_cmp;
	heap->root = NULL;

	return (heap);
}
