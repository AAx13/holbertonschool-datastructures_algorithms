#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

/**
 * main - main crossroad in processing monty opcodes.
 *
 * Return: 0.
 */
int main(int ac, char **av)
{
	FILE *fp;
	char buf[80];
	char **tokens;
	unsigned int i;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open file */
	fp = fopen(av[1], "r");
	if (!fp)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	i = 1;
	/* retrieve every line from file until EOF */
	while(fgets(buf, sizeof(buf), fp))
	{
		/* parse opcode command */
		tokens = parse(buf);

		if (*tokens && strcmp(*tokens, "push") == 0)
		{
			/* build stack */
		}
		else
		{
			/* execute opcode on the stack. */
		}
		i++;
	}

	fclose(fp);

	return (0);
}
