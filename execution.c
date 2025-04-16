#include "simpleShell.h"

/**
 * execution - execute the command
 *
 * @command: the command and its parameter
 * @error: the return of findExec
 *
 * Return: 1 if error or 0 otherwise
 */

int execution(char **command)
{
	pid_t child;
	int status = 0;

	if (access(command[0], F_OK) == -1)
	{
		if (isatty(STDIN_FILENO))
			printf("./hsh: no such file or directory\n");
		return (-1);
	}
	child = fork();
	if (child == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child == 0)
	{
		if (execve(command[0], command, NULL) == -1)
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
