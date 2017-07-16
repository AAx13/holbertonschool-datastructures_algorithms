#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the nodes with at least
 * 1 child in a binary tree.
 * @tree: A pointer to a binary tree node.
 *
 * Return: Number of nodes with at least 1 child or 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	if (tree->left && tree->right)
	{
		return (1 + binary_tree_nodes(tree->left)
			+ binary_tree_nodes(tree->right));
	}

	if (tree->left)
	{
		return (1 + binary_tree_nodes(tree->left));
	}

	if (tree->right)
	{
		return (1 + binary_tree_nodes(tree->right));
	}

	return (0);
}
