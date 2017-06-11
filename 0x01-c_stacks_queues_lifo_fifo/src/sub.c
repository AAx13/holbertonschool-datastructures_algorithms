#include <stdio.h>
#include <stdlib.h>
#include "../monty.h"

/**
 * op_sub - subtracts the top element of the stack from the second top element.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (!head || head->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head->next->n -= head->n;
	head->next->prev = NULL;
	*stack = head->next;
	free(head);
}
