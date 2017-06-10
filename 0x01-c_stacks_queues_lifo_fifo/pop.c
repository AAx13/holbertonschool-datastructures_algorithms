#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * pop - removes the top element of the stack.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp_node;

	if (!*stack)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (*stack)
	{
		if ((*stack)->next == NULL)
		{
			tmp_node = *stack;
			if (!(*stack)->prev)
			{
				free(*stack);
				*stack = NULL;
				break;
			}
			*stack = (*stack)->prev;
			(*stack)->next = NULL;
			free(tmp_node);
			break;
		}
		*stack = (*stack)->next;
	}
}
