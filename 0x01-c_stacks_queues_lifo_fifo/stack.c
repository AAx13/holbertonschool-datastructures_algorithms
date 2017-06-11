#include <stdio.h>
#include "monty.h"

/**
 * op_stack - pushes to a stack.
 * @stack: A stack struct to operate on.
 * @new_node: A new node to push.
 *
 * Return: Void.
 */
void op_stack(stack_t **stack, stack_t *new_node)
{
	stack_t *head;

	head = *stack;
	new_node->next = head;
	head->prev = new_node;
	new_node->prev = NULL;
	*stack = new_node;
}
