#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal.
 * @tree: A node in a binary tree.
 * @func: Function pointer to one that prints the value of a node.
 *
 * Return: Void.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !tree->n)
	{
		return;
	}

	func(tree->n);
	if (tree->left)
	{
		binary_tree_preorder(tree->left, func);
	}

	if (tree->right)
	{
		binary_tree_preorder(tree->right, func);
	}
}
