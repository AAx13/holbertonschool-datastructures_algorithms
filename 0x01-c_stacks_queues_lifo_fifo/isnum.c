#include <ctype.h>
#include "monty.h"

/**
 * isnum - checks if string is a number.
 * @str: A string to check.
 *
 * Return: 0 if true else 1.
 */
int isnum(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-')
		{
			i++;
		}

		if (isdigit(str[i]) == 0)
		{
			return (1);
		}
	}

	return (0);
}
