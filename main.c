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

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("hsh~$ ");
		}
		resu = getline(&line, &len, stdin);
		if (resu == -1)
		{
			free(line);
			exit(99);
		}
		strtoken(command, line, " ");
		execution(command);
	}
	free(line);
	return (0);
}
