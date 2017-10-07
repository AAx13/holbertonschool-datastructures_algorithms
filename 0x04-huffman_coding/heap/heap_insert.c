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
		if (!current_node->data)
		{
			tmp_data = current_node->data;
			current_node->data = current_node->parent->data;
			current_node->parent->data = tmp_data;
		}
		else if (current_node->parent->data && heap->data_cmp(current_node->data
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

	index = heap->size;
	if (index == 0)
		heap_array = malloc(sizeof(binary_tree_node_t *));
	else
		heap_array = realloc(heap_array, sizeof(binary_tree_node_t *)
				     * (heap->size + 1));
	if (!heap || !heap_array)
		return (NULL);

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

	return (heap_array[index]);
}
