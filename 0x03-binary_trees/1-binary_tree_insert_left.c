#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node.
 * @parent: Parent of this new node or NULL if root.
 * @value: Value to be inserted into new node.
 *
 * Return: Pointer to new node or NULL if failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *old_left;

	if (!parent)
	{
		return (NULL);
	}

	old_left = parent->left;
	parent->left = binary_tree_node(parent, value);
	if (!parent->left)
	{
		return (NULL);
	}

	parent->left->left = old_left;
	if (old_left)
	{
		old_left->parent = parent->left;
	}

	return (old_left);
}
