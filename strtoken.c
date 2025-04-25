#include "simpleShell.h"

/**
 * strtoken - strok the line given into an array of all element
 *
 * @line: the line to strok
 * @command: the array of element of the command
 * @separator: the character use to separate
 * Return: always 0
 */

int strtoken(char **command, char *line, char *separator)
{
	int i = 0;

	line = strtok(line, "\t\n\r");

	for (line = strtok(line, separator) ; line != NULL;
			line = strtok(NULL, separator))
	{
		if (i == 0)
			strcpy(command[i], line);
		else
			command[i] = line;
		i++;
	}
	if (i > 0)
	{
		command[i] = NULL; /* set the end of the command */
		return (0);
	}
	return (1); /* command line empty */
}
