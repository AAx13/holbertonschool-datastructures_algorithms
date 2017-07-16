#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf.
 * @node: A binary tree node.
 *
 * Return: 1 if node is a leaf. Otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->left || node->right)
	{
		return (0);
	}
	return (1);
}
