#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @node: A pointer to a node in a binary tree.
 *
 * Return: Depth or 0 if NULL.
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (!node)
	{
		return (0);
	}

	if (node->parent)
	{
		return (1 + binary_tree_depth(node->parent));
	}

	return (0);
}
