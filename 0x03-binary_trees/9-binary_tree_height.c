#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: A pointer to a node in a binary tree.
 *
 * Return: Height or 0 if NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	if (tree->left)
	{
		return (1 + binary_tree_height(tree->left));
	}

	if (tree->right)
	{
		return (1 + binary_tree_height(tree->right));
	}

	return (0);
}
