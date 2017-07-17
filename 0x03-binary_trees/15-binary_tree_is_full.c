#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if full. 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree || !tree->left || !tree->right)
	{
		return (0);
	}
	else if (tree->right && tree->left)
	{
		return (1);
	}

	return (0);
}
