#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../monty.h"

/**
 * parse - checks line from file for a single command and argument.
 * @line: A line from file.
 * @tokens: Array of strings.
 *
 * Return: Void.
 */
void parse(char *line, char **tokens)
{
	int i;
	char *token;

	token = strtok(line, "\n ");
	for (i = 0; token && i < 2; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n ");
	}
	tokens[i] = NULL;
}
