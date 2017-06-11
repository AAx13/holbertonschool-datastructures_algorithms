#include <string.h>
#include "monty.h"

/**
 * push_check - checks for push, queue, and stack opcode commands.
 * @stack: The stack to operate on.
 * @tokens: Tokenized opcode command.
 * @ln: Line number of the current opcode in operation.
 * @sentinel: Sentinel variable dictating if push will be on stack or queue.
 *
 * Return: 0 if stack queue or push. Else 1.
 */
int push_check(stack_t **stack, char **tokens, unsigned int ln, int *sentinel)
{
	if (strcmp(tokens[0], "stack") == 0)
	{
		*sentinel = 0;
		return (0);
	}
	else if (strcmp(tokens[0], "queue") == 0)
	{
		*sentinel = 1;
		return (0);
	}
	else if (strcmp(tokens[0], "push") == 0)
	{
		op_push(stack, tokens, ln, sentinel);
		return (0);
	}

	return (1);
}
