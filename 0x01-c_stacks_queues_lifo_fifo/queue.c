#include <stdio.h>
#include "monty.h"

/**
 * op_queue - pushes to a queue.
 * @stack: A stack struct to operate on.
 * @new_node: A new node to push.
 *
 * Return: Void.
 */
void op_queue(stack_t **stack, stack_t *new_node)
{
	stack_t *head;

	head = *stack;
	for (; head; head = head->next)
	{
		if (head->next == NULL)
		{
			head->next = new_node;
			new_node->next = NULL;
			new_node->prev = head;
		}
	}
}
