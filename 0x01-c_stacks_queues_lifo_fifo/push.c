#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * push - push an element onto the stack.
 * @stack: The stack to operate on.
 * @tokens: Tokenized opcode command.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: Void.
 */
void push(stack_t **stack, char **tokens, unsigned int line_number)
{
	stack_t *new_node;

	if (!tokens[1] || isnum(tokens[1]) != 0)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* if stack is empty */
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		while (*stack)
		{
			if ((*stack)->next == NULL)
			{
				(*stack)->next = new_node;
				new_node->prev = *stack;
				new_node->next = NULL;
				break;
			}
			*stack = (*stack)->next;
		}
	}
	new_node->n = atoi(tokens[1]);
	free(tokens);
}
