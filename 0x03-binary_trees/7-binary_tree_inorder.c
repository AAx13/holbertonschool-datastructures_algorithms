#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary tree using in-order traversal.
 * @tree:A node in a binary tree.
 * @func: Function pointer to one that prints the value of a node.
 *
 * Return: Void.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree->left)
	{
		binary_tree_inorder(tree->left, func);
	}

	func(tree->n);

	if (tree->right)
	{
		binary_tree_inorder(tree->right, func);
	}
}
