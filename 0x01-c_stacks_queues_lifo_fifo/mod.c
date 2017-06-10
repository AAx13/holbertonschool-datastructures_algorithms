#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * op_mod - computes the remainder of the division of
 * the second top element of the stack by the top element.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *head;

	if (!*stack || (*stack && (*stack)->next == NULL))
	{
		printf("L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	while (*stack)
	{
		if ((*stack)->next->next == NULL)
		{
			tail = (*stack)->next;
			if (tail->n == 0)
			{
				printf("L%d: division by zero\n", line_number);
				exit(EXIT_FAILURE);
			}
			(*stack)->n %= tail->n;
			(*stack)->next = NULL;
			*stack = head;
			free(tail);
			break;
		}
		*stack = (*stack)->next;
	}
}
