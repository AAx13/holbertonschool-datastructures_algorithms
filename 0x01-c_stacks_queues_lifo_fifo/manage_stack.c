#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "monty.h"

/**
 * manage_stack - manages the passing of opcode to their respective functions.
 * @stack: The stack to operate on.
 * @tokens: Tokenized opcode command.
 * @line_number: Line number of the current opcode in operation.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int manage_stack(stack_t **stack, char **tokens, unsigned int line_number)
{
	int i;
	instruction_t func[] = {

		{ "pall", &pall },
		{ "pint", &pint },
		{ "pop", &pop },
		{ "swap", &swap },
		{ "add", &add },
		{ "nop", &nop },
		{ NULL, NULL }
	};

	if (!tokens[0])
	{
		free(tokens);
		return (EXIT_FAILURE);
	}

	if (strcmp(tokens[0], "push") == 0)
	{
		push(stack, tokens, line_number);
		return (EXIT_SUCCESS);
	}

	for (i = 0; func[i].opcode; i++)
	{
		if (strcmp(func[i].opcode, tokens[0]) == 0)
		{
			free(tokens);
			func[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	printf("L%d: unknown instruction %s\n", line_number, tokens[0]);
	free(tokens);
	exit(EXIT_FAILURE);

	return (0);
}
