#include "simpleShell.h"

/**
 * execution - execute the command
 *
 * @command: the command and its parameter
 *
 * Return: 1 if error or 0 otherwise
 */

int execution(char **command)
{
	pid_t child;
	int status = 0;

	child = fork();
	if (child == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			return (1);
		}
		return (0);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
