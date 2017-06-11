#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * op_swap - swaps the top two elements of the stack.
 * @stack: A stack to operate on.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head, *tail, *tmp_node;

	head = *stack;
	if (!head || head->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp_node = head->next;
	tail = tmp_node->next;

	tail->prev = head;
	head->next = tail;

	tmp_node->prev = NULL;
	head->prev = tmp_node;

	tmp_node->next = head;
	*stack = tmp_node;
}
