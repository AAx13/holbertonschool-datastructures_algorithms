#include "heap.h"

/**
 * min_heapify - sort a binary tree to Min Binary Heap format.
 * @heap: Pointer to a heap data structure.
 * @last_node: Last node inserted to the tree.
 *
 * Return: Void.
 */
void min_heapify(heap_t *heap, binary_tree_node_t *last_node)
{
	binary_tree_node_t *current_node;
	void *tmp_data;

	current_node = last_node;
	while (current_node->parent)
	{
		if (current_node->parent->data && heap->data_cmp(current_node->data
								 , current_node->parent->data) < 0)
		{
			tmp_data = current_node->data;
			current_node->data = current_node->parent->data;
			current_node->parent->data = tmp_data;
		}
		current_node = current_node->parent;
	}
}

/**
 * heap_insert - inserts a value in a Min Binary Heap.
 * @heap: A pointer to the heap in which the node has to be inserted.
 * @data: A pointer containing the data to store in the new node.
 *
 * Return: A pointer to the last created node containing data,
 * or NULL if it fails.
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	static binary_tree_node_t **heap_array;
	size_t index, parent_index;
	int null_data[1], i;

	index = heap->size, *null_data = 0;
	if (index == 0)
		heap_array = malloc(8);
	else
		heap_array = realloc(heap_array, 8 * (heap->size + 1));

	if (!heap || !heap_array)
		return (NULL);

	if (!data)
		heap_array[index] = binary_tree_node(NULL, null_data);
	else
		heap_array[index] = binary_tree_node(NULL, data);

	if (index == 0)
	{
		heap->root = heap_array[index];
	}
	else
	{
		parent_index = (index + 1) / 2;
		heap_array[index]->parent = heap_array[parent_index - 1];
		if (parent_index * 2 == index + 1)
		{
			heap_array[parent_index - 1]->left = heap_array[index];
		}
		else if (parent_index * 2 + 1 == index + 1)
		{
			heap_array[parent_index - 1]->right = heap_array[index];
		}

	}
	min_heapify(heap, heap_array[index]);
	heap->size++;

	printf("Heap Array:\n");
	for (i = 0; i < (int)heap->size; i++)
	{
		printf("[ %d ] ", *((int *)heap_array[i]->data));
	}
	printf("\n\n");
	printf("Heap Tree:\n");

	return (heap_array[index]);
}
