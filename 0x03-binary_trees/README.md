# Binary Trees Project

[binary_tree_node](../0x03-binary_trees/0-binary_tree_node.c)
```c
/* binary_tree_node - creates a binary tree node. */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

[binary_tree_insert_left](../0x03-binary_trees/1-binary_tree_insert_left.c)
```c
/* binary_tree_insert_left - inserts a node as the left-child of another node. */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
```

[binary_tree_insert_right](../0x03-binary_trees/2-binary_tree_insert_right.c)
```c
/* binary_tree_insert_right - inserts a node as the right-child of a node. */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
```

[binary_tree_delete](../0x03-binary_trees/3-binary_tree_delete.c)
```c
/* binary_tree_delete - deletes an entire binary tree. */
void binary_tree_delete(binary_tree_t *tree);
```

[binary_tree_is_leaf](../0x03-binary_trees/4-binary_tree_is_leaf.c)
```c
/* binary_tree_is_leaf - checks if a node is a leaf. */
 int binary_tree_is_leaf(const binary_tree_t *node);
```

[binary_tree_is_root](../0x03-binary_trees/5-binary_tree_is_root.c)
```c
/* binary_tree_is_root - checks if a given node is a root. */
int binary_tree_is_root(const binary_tree_t *node);
```

[binary_tree_preorder](../0x03-binary_trees/6-binary_tree_preorder.c)
```c
/* binary_tree_preorder - goes through a binary tree using pre-order traversal. */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
```

[binary_tree_inorder](../0x03-binary_trees/7-binary_tree_inorder.c)
```c
/* binary_tree_inorder - goes through a binary tree using in-order traversal. */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
```

[binary_tree_postorder](../0x03-binary_trees/8-binary_tree_postorder.c)
```c
/* binary_tree_postorder - goes through a binary tree */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
```

[binary_tree_height](../0x03-binary_trees/9-binary_tree_height.c)
```c
/* binary_tree_height - measures the height of a binary tree. */
size_t binary_tree_height(const binary_tree_t *tree);
```

[binary_tree_depth](../0x03-binary_trees/10-binary_tree_depth.c)
```c
* binary_tree_depth - measures the depth of a node in a binary tree. */
size_t binary_tree_depth(const binary_tree_t *node);
```

[binary_tree_size](../0x03-binary_trees/11-binary_tree_size.c)
```c
/* binary_tree_size - measures the size of a binary tree. */
size_t binary_tree_size(const binary_tree_t *tree);
```

[binary_tree_leaves](../0x03-binary_trees/12-binary_tree_leaves.c)
```c
/* binary_tree_leaves - counts the leaves in a binary tree. */
size_t binary_tree_leaves(const binary_tree_t *tree);
```

[binary_tree_nodes](../0x03-binary_trees/13-binary_tree_nodes.c)
```c
/* binary_tree_nodes - counts the nodes with at least. */
size_t binary_tree_nodes(const binary_tree_t *tree);
```

[binary_tree_balance](../0x03-binary_trees/14-binary_tree_balance.c)
```c
/* binary_tree_balance - measures the balance factor of a binary tree. */
int binary_tree_balance(const binary_tree_t *tree);
```

[binary_tree_is_full](../0x03-binary_trees/15-binary_tree_is_full.c)
```c
/* binary_tree_is_full - checks if a binary tree is full. */
int binary_tree_is_full(const binary_tree_t *tree);
```

[binary_tree_is_perfect](../0x03-binary_trees/16-binary_tree_is_perfect.c)
```c
/* binary_tree_is_perfect - checks if a binary tree is perfect. */
int binary_tree_is_perfect(const binary_tree_t *tree);
```

[binary_tree_sibling](../0x03-binary_trees/17-binary_tree_sibling.c)
```c
/* binary_tree_sibling - finds the sibling of a node. */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
```

[binary_tree_uncle](../0x03-binary_trees/18-binary_tree_uncle.c)
```c
/* binary_tree_uncle - finds the uncle of a node. */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
```