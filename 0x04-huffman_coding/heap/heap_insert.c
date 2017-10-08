#include "heap.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: A pointer to a node in a binary tree.
 *
 * Return: Height or 0 if NULL.
 */
size_t binary_tree_height(const binary_tree_node_t *tree)
{
	size_t left, right;

	if (!tree)
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
size_t binary_tree_leaves(const binary_tree_node_t *tree)
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
size_t binary_tree_nodes(const binary_tree_node_t *tree)
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
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: 1 if perfect. 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_node_t *tree)
{
	int height, nodes;

	height = binary_tree_height(tree) - 1;
	nodes = binary_tree_leaves(tree) + binary_tree_nodes(tree);

	if ((power(2, height) - 1) == nodes)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * min_heapify - sort a binary tree to Min Binary Heap format.
 * @heap: Pointer to a heap data structure.
 * @last_node: Last node inserted to the tree.
 *
 * Return: Void.
 */
void min_heapify(heap_t *heap, binary_tree_node_t *last_node)
{
	binary_tree_node_t *current_node;
	void *tmp_data;

	current_node = last_node;
	while (current_node->parent)
	{
		if (!current_node->data || (current_node->parent->data &&
					    heap->data_cmp(current_node->data, current_node->parent->data) < 0))
		{
			tmp_data = current_node->data;
			current_node->data = current_node->parent->data;
			current_node->parent->data = tmp_data;
		}
		current_node = current_node->parent;
	}
}

/**
 *
 */
char *num_to_binary(heap_t *heap, int num)
{
	char *binary_string;
	size_t index, i;

	index = binary_tree_height(heap->root);
	if (index != 1 && binary_tree_is_perfect(heap->root) != 1)
	{
		index--;
	}

	binary_string = calloc(index + 2, 1);
	memset(binary_string, '0', index + 2);
	while (num > 0)
	{
		if (num % 2 == 1)
		{
			binary_string[index] = '1';
		}
		index--;
		num /= 2;
	}

	for (i = 0; i < strlen(binary_string); i++)
	{
		printf("[%c] ", binary_string[i]);
	}
	printf("\n");

	return (binary_string);
}

/**
 * heap_insert - inserts a value in a Min Binary Heap.
 * @heap: A pointer to the heap in which the node has to be inserted.
 * @data: A pointer containing the data to store in the new node.
 *
 * Return: A pointer to the last created node containing data,
 * or NULL if it fails.
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *node, *tmp_node, *parent;
	size_t left, right, i;
	char *binary_string;

	left = 0, right = 0;
	if (!heap->root)
	{
		node = binary_tree_node(NULL, data);
		heap->root = node;
	}
	else
	{
		tmp_node = heap->root;
		binary_string = num_to_binary(heap, (int)heap->size + 1);
		for (i = 1; i < strlen(binary_string) - 1; i++)
		{
			parent = tmp_node;
			if (binary_string[i] == '0')
			{
				tmp_node = tmp_node->left;
				left++;
				right = 0;
			}
			else
			{
				tmp_node = tmp_node->right;
				right++;
				left = 0;
			}
		}
		node = binary_tree_node(parent, data);
		if (left > right)
			parent->left = node;
		else
			parent->right = node;
		free(binary_string);
		min_heapify(heap, node);
	}
	heap->size++;
	return (node);
}
