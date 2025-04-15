#include "simpleShell.h"

/**
 * execution - execute the command
 *
 * @command: the command and its parameter
 * @error: the return of findExec
 *
 * Return: 1 if error or 0 otherwise
 */

int execution(char **command, int error)
{
	pid_t child;
	int status, test = 468468;

	if (error == 1)
	{
		printf("./hsh : no such file or directory");
		status = 1;
	}
	else
	{
		child = fork();
		if (child == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child == 0)
		{
			if ((test = execve(command[0], command, NULL)) != -1)
				return (0);
			printf("./hsh : no such file or directory\n");
			kill(getpid());
			return (1);
		}
		else
		{
			wait(&status);
		}
	}
	return (status);
}
