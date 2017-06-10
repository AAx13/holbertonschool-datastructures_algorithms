#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail;

	if (*stack && (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = *stack;
	while (*stack)
	{
		if ((*stack)->next == NULL)
		{
			tail = *stack;
		}
		*stack = (*stack)->next;
	}
	*stack = tail->prev;
	tail->prev = NULL;

	tail->next = head->next;
	head->next->prev = tail;
	head->next = NULL;

	(*stack)->next = head;
	head->prev = *stack;
	*stack = tail;
}
