#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * op_pint - prints the value at the top of the stack.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if (!*stack)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	while (*stack)
	{
		if ((*stack)->next == NULL)
		{
			printf("%d\n", (*stack)->n);
			*stack = head;
			break;
		}
		*stack = (*stack)->next;
	}
}
