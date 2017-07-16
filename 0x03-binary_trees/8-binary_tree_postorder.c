#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary tree
 * using post-order traversal.
 * @tree:A node in a binary tree.
 * @func: Function pointer to one that prints the value of a node.
 *
 * Return: Void.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}

	if (tree->left)
	{
		binary_tree_postorder(tree->left, func);
	}

	if (tree->right)
	{
		binary_tree_postorder(tree->right, func);
	}

	func(tree->n);
}
