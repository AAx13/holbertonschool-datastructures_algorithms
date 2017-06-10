#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * op_pstr -  prints the string starting at the top of the stack.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void op_pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *head;

	head = *stack;
	while (head)
	{
		if (head->n == 0 || head->n < 0 || head->n > 127)
		{
			break;
		}
		putchar(head->n);
		head = head->next;
	}
	putchar('\n');
}
