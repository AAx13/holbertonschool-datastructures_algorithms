#include <stdlib.h>
#include "monty.h"

/**
 * free_stack - frees the stack.
 * @stack: A stack to operate on.
 *
 * Return: Void.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp_node, *head;

	tmp_node = NULL;
	head = *stack;
	while (head)
	{
		tmp_node = head;
		head = head->next;
		free(tmp_node);
	}
}
