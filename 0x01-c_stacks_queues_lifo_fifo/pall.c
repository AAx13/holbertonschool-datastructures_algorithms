#include <stdio.h>
#include "monty.h"

/**
 * pall - print the stack.
 * @stack: The stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head;

	head = *stack;
	while (*stack)
	{
		if ((*stack)->next == NULL)
		{
			while (*stack)
			{
				printf("%d\n", (*stack)->n);
				*stack = (*stack)->prev;
			}
			break;
		}
		*stack = (*stack)->next;
	}
	*stack = head;
}
