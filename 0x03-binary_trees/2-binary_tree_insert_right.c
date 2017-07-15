#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of a node.
 * @parent: Parent of this new node or NULL if root.
 * @value: Value to be inserted into new node.
 *
 * Return: Pointer to new node or NULL if failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *old_right;

	if (!parent)
	{
		return (NULL);
	}

	old_right = parent->right;
	parent->right = binary_tree_node(parent, value);
	if (!parent->right)
	{
		return (NULL);
	}

	parent->right->right = old_right;
	if (old_right)
	{
		old_right->parent = parent->right;
	}

	return (old_right);
}
