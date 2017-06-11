#include <stdio.h>
#include "monty.h"

/**
 * op_pall - print the stack.
 * @stack: The stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void op_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head;

	head = *stack;
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
