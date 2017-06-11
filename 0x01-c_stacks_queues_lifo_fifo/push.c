#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * op_push - push an element onto the stack.
 * @stack: The stack to operate on.
 * @tokens: Tokenized opcode command.
 * @ln: Line number of the current opcode in operation.
 * @sentinel: Sentinel variable dictating if push will be on stack or queue.
 *
 * Return: Void.
 */
void op_push(stack_t **stack, char **tokens, unsigned int ln, int sentinel)
{
	stack_t *new_node, *head;

	if (!tokens[1] || isnum(tokens[1]) != 0)
		printf("L%d: usage: push integer\n", ln);
		exit(EXIT_FAILURE);

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);

	head = *stack;
	if (head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		*stack = new_node;
	}
	else if (sentinel == 1)
	{
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
	else
	{
		new_node->next = head;
		head->prev = new_node;
		new_node->prev = NULL;
		*stack = new_node;
	}
	new_node->n = atoi(tokens[1]);
}
