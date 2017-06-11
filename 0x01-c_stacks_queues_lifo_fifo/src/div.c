#include <stdio.h>
#include <stdlib.h>
#include "../monty.h"

/**
 * op_div - divides the second top element of the stack by the top element.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	head = *stack;
	if (!head || head->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	head->next->n /= head->n;
	head->next->prev = NULL;
	*stack = head->next;
	free(head);
}
