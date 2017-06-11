#include <stdlib.h>
#include <stdio.h>
#include "../monty.h"

/**
 * op_pop - removes the top element of the stack.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (!head)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	*stack = head->next;
	free(head);
}
