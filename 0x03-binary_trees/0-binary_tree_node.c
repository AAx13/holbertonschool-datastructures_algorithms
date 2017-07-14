#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node.
 * @parent: Parent of this new node or NULL if root.
 * @value: Value to be inserted into new node.
 *
 * Return: Pointer to new node or NULL if failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
