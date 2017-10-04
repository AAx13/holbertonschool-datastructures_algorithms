#include "heap.h"

/**
 * binary_tree_node - creates a generic Binary Tree node.
 * @parent: Pointer to the parent node of the node to be created.
 * @data: Data to be stored in the node.
 *
 * Return: Pointer to a binary tree node or NULL if failed.
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *node;

	node = malloc(sizeof(binary_tree_node_t));
	if (!node)
	{
		return (NULL);
	}

	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = parent;

	return (node);
}
