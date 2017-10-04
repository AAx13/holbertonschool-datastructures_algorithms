#include "heap.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node:  A pointer to a binary tree node.
 *
 * Return: The sibling to the node passed. Or NULL if failed.
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
 * build_tree - insert nodes as they arrive.
 * @last_node: Last node inserted.
 * @data: Data to store at the new node.
 *
 * Return: Newest node inserted.
 */
binary_tree_node_t *build_tree(binary_tree_node_t *last_node, void *data)
{
	binary_tree_node_t *tmp_node, *node;

	tmp_node = last_node;
	if (!tmp_node->parent && !binary_tree_sibling(tmp_node))
	{
		node = binary_tree_node(tmp_node, data);
		tmp_node->left = node;
		return (node);
	}
	else if (!binary_tree_sibling(tmp_node))
	{
		node = binary_tree_node(tmp_node->parent, data);
		tmp_node->parent->right = node;
		return (node);
	}

	tmp_node = binary_tree_sibling(tmp_node);
	if (binary_tree_uncle(tmp_node))
	{
		tmp_node = binary_tree_uncle(tmp_node);
		if (tmp_node->left)
		{
			tmp_node = tmp_node->left;
		}
	}

	if (!tmp_node->left)
	{
		node = binary_tree_node(tmp_node, data);
		tmp_node->left = node;
		return (node);
	}

	return (NULL);
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
	static binary_tree_node_t *last_node;
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
		last_node = node;
		printf("addy of last node: %p\n", (void *)last_node);
		return (node);
	}
	node = build_tree(last_node, data);
	if (!node)
	{
		return (NULL);
	}
	last_node = node;
	min_heapify(heap, node);
	heap->size += 1;

	return (node);
}
