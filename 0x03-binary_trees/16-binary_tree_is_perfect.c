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
 * binary_tree_leaves - counts the leaves in a binary tree.
 * @tree: A pointer to a binary tree.
 *
 * Return: Number of leaves in the binary tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	if (!tree->left && !tree->right)
	{
		return (1);
	}

	return (binary_tree_leaves(tree->left)
		+ binary_tree_leaves(tree->right));
}

/**
 * binary_tree_nodes - counts the nodes with at least
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

/**
 * power - calculates the exponential value of a number.
 * @num: A number.
 * @exponent: An exponent.
 *
 * Return: Value of num to the power of exponent.
 */
int power(int num, int exponent)
{
	int value;

	value = num;
	while (exponent)
	{
		value *= num;
		exponent--;
	}

	return (value);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if perfect. 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, nodes;

	height = binary_tree_height(tree);
	nodes = binary_tree_leaves(tree) + binary_tree_nodes(tree);

	if (power(2, height) - 1 == nodes)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
