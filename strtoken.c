#include "simpleShell.h"

/**
 * strtoken - strok the line given into an array of all element
 *
 * @line: the line to strok
 * @command: the array of element of the command
 *
 * Return: always 0
 */

char **strtoken(char **command, char *line)
{
	int i = 0;

	line = strtok(line, "\n");

	for (line = strtok(line, " ") ; line != NULL ; line = strtok(NULL, " "))
	{
		command[i] = line;
		i++;
	}

	return (0);
}
