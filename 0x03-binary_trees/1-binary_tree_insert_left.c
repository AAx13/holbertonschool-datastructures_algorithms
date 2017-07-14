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
	binary_tree_t *new_node, *tmp_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node || parent->n < value)
	{
		return (NULL);
	}

	if (parent->left)
	{
		tmp_node = parent->left;
		parent->left = new_node;
		new_node->left = tmp_node;
		tmp_node->parent = new_node;
	}
	else
	{
		parent->left = new_node;
		new_node->left = NULL;
	}
	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;

	return (new_node);
}
