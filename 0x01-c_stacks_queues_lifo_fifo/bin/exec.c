#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - pushes an element onto the stack.
 * @tokens: Tokenized command from file.
 * @line_number: Integer representing the line where this command exists.
 *
 * Return: Pointer to the current stack.
 */
stack_t **push(char **tokens, int line_number)
{
	stack_t *node;

	if (!tokens[1] || (tokens[1] && isdigit(tokens[1][0]) == 0))
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
}
