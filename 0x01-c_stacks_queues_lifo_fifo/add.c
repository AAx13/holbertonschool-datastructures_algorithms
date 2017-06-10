#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *prev_node, *head;

	if (!*stack || (*stack && (*stack)->next == NULL))
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	while (*stack)
	{
		if ((*stack)->next == NULL)
		{
			prev_node = (*stack)->prev;
			prev_node->n += (*stack)->n;
			prev_node->next = NULL;
			free(*stack);
			*stack = head;
			break;
		}
		*stack = (*stack)->next;
	}
}
