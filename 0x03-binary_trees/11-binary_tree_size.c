#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: A binary tree to measure.
 *
 * Return: Size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	if (tree->left && tree->right)
	{
		return (1 + binary_tree_size(tree->left)
			  + binary_tree_size(tree->right));
	}
	else if (tree->left && !tree->right)
	{
		return (1 + binary_tree_size(tree->left));
	}
	else if (tree->right && !tree->left)
	{
		return (1 + binary_tree_size(tree->right));
	}
	else
	{
		return (1);
	}

	return (0);
}
