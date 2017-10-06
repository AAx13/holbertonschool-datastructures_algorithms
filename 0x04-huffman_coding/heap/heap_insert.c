#include "heap.h"

/**
 * binary_tree_sibling - returns the sibling of node passed.
 * @node: Node to find a sibling for.
 *
 * Return: Sibling of passed node or NULL.
 */
binary_tree_node_t *binary_tree_sibling(binary_tree_node_t *node)
{
	if (!node || !node->parent)
	{
		return (NULL);
	}

	if (node->parent->left == node)
	{
		return (node->parent->right);
	}

	if (node->parent->right == node)
	{
		return (node->parent->left);
	}

	return (NULL);
}

/**
 * binary_tree_uncle - finds the uncle of a node.
 * @node:  A pointer to a binary tree node.
 *
 * Return: The uncle of the node passed. Or NULL if failed.
 */
binary_tree_node_t *binary_tree_uncle(binary_tree_node_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
	{
		return (NULL);
	}

	return (binary_tree_sibling(node->parent));
}

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
 * insert - insert nodes into a heap data structure.
 * @heap: A heap data structure.
 * @last_node: Last node inserted.
 * @data: Data to store at the new node.
 *
 * Return: Newest node inserted.
 */
binary_tree_node_t *insert(heap_t *heap, void *data)
{
	binary_tree_node_t *tmp_node, *node;
	int position, left, right;

	heap->size += 1;
	left = 0, right = 0;
	position = (int)heap->size;
	tmp_node = heap->root;
	while (position > 1)
	{
		position = position / 2;
		if (position % 2 == 0 || (position % 2 == 1 && !tmp_node->left))
		{
			if (!tmp_node->left)
			{
				left++;
				right = 0;
				break;
			}
			tmp_node = tmp_node->left;
		}
		else
		{
			if (!tmp_node->right)
			{
				right++;
				left = 0;
				break;
			}
			tmp_node = tmp_node->right;
		}
	}
	node = binary_tree_node(tmp_node, data);

	if (left > right)
		tmp_node->left = node;
	else
		tmp_node->right = node;

	return (node);
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
	binary_tree_node_t *node;

	node = malloc(sizeof(binary_tree_node_t));
	if (!heap || !node)
	{
		return (NULL);
	}

	if (!heap->root)
	{
		node = binary_tree_node(NULL, data);
		if (!node)
		{
			return (NULL);
		}
		heap->size += 1;
		heap->root = node;

		return (node);
	}
	node = insert(heap, data);
	min_heapify(heap, node);

	return (node);
}
