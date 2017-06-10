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
	stack_t *tmp_node;

	tmp_node = NULL;
	while (*stack)
	{
		if (!(*stack)->next)
		{
			while (*stack)
			{
				tmp_node = *stack;
				*stack = (*stack)->prev;
				free(tmp_node);
			}
			break;
		}
		*stack = (*stack)->next;
	}
}
