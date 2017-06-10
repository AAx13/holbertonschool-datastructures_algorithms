#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tail, *head;

	if (!*stack || (*stack && (*stack)->next == NULL))
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	while (*stack)
	{
		if ((*stack)->next->next == NULL)
		{
			tail = (*stack)->next;
			(*stack)->n -= tail->n;
			(*stack)->next = NULL;
			free(tail);
			*stack = head;
			break;
		}
		*stack = (*stack)->next;
	}
}
