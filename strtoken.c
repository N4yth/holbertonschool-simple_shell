#include "simpleShell.h"

/**
 * strtoken - strok the line given into an array of all element
 *
 * @line: the line to strok
 * @command: the array of element of the command
 *
 * Return: always 0
 */

char **strtoken(char **command, char *line, char *separator)
{
	int i = 0;

	line = strtok(line, "\n");

	for (line = strtok(line, separator) ; line != NULL ;
			line = strtok(NULL, separator))
	{
		command[i] = line;
		i++;
	}

	return (0);
}
