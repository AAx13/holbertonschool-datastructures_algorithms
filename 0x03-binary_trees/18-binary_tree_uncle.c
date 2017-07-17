#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node:  A pointer to a binary tree node.
 *
 * Return: The sibling to the node passed. Or NULL if failed.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
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
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
	{
		return (NULL);
	}

	return (binary_tree_sibling(node->parent));
}
