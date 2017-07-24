#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: A pointer to a node in a binary tree.
 *
 * Return: Height or 0 if NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree || (!tree->left && !tree->right))
	{
		return (0);
	}

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	if (left > right)
	{
		return (left + 1);
	}
	else
	{
		return (right + 1);
	}
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * to measure the balance factor of.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: Balance factor of the tree (int).
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right;

	left = 0;
	right = 0;
	if (!tree)
	{
		return (0);
	}

	if (tree->left)
	{
		left = binary_tree_height(tree->left) + 1;
	}

	if (tree->right)
	{
		right = binary_tree_height(tree->right) + 1;
	}

	return (left - right);
}
