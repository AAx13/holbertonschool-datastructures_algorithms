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
	while (*stack)
	{
		if ((*stack)->next == NULL)
		{
			while (*stack)
			{
				if ((*stack)->n == 0 || ((*stack)->n < 0 || (*stack)->n > 127))
				{
					break;
				}
				printf("%c\n", (*stack)->n);
				*stack = (*stack)->prev;
			}
		}
		*stack = (*stack)->next;
	}
	*stack = head;
}
