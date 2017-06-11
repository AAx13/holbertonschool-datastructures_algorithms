#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../monty.h"

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
	static int sentinel;
	instruction_t func[] = {

		{ "pall", &op_pall },
		{ "pint", &op_pint },
		{ "pop", &op_pop },
		{ "swap", &op_swap },
		{ "add", &op_add },
		{ "nop", &op_nop },
		{ "sub", &op_sub },
		{ "div", &op_div },
		{ "mul", &op_mul },
		{ "mod", &op_mod },
		{ "pchar", &op_pchar },
		{ "pstr", &op_pstr },
		{ "rotl", &op_rotl },
		{ "rotr", &op_rotr },
		{ NULL, NULL }
	};

	if (strcmp(tokens[0], "stack") == 0)
	{
		sentinel = 0;
		return (EXIT_SUCCESS);
	}
	else if (strcmp(tokens[0], "queue") == 0)
	{
		sentinel = 1;
		return (EXIT_SUCCESS);
	}

	if (strcmp(tokens[0], "push") == 0)
	{
		op_push(stack, tokens, line_number, sentinel);
		return (EXIT_SUCCESS);
	}

	for (i = 0; func[i].opcode; i++)
	{
		if (strcmp(func[i].opcode, tokens[0]) == 0)
		{
			func[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	printf("L%d: unknown instruction %s\n", line_number, tokens[0]);
	exit(EXIT_FAILURE);

	return (0);
}
