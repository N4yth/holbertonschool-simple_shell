#include "simpleShell.h"

/**
 * main - Entry point
 *
 *Return: always 0
 */
int main(void)
{
	int resu = 0;
	size_t len = 0;
	char *line = "";
	char *command[4096] = {""};

	command[0] = malloc(255);
	if (command[0] == NULL)
		return (0);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("hsh~$ ");
		resu = getline(&line, &len, stdin);
		if (resu == -1)
		{
			free(command[0]);
			free(line);
			exit(0);
		}
		strtoken(command, line, " ");
		if (findExec(command))
		{
			if (execution(command) == 1)
			{
				free(command[0]);
				free(line);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(command[0]);
	free(line);
	return (0);
}
