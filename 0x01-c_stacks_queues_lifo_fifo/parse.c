#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * parse - checks line from file for a single command and argument.
 * @line: A line from file.
 *
 * Return: Tokenized line from file.
 */
char **parse(char *line)
{
	int i;
	char *token;
	char **tokens;

	tokens = malloc(sizeof(char *) * 3);
	if (!tokens)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, "\n ");
	for (i = 0; token && i < 2; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
