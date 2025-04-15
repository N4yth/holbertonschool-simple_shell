#include "simpleShell.h"

/**
 * main - Entry point
 *
 *Return: always 0
 */
int main(void)
{
	int resu;
	size_t len;
	char *line;
	char **command;

	command = malloc(255);
	if (command == NULL)
	{
		return (1);
	}
	while (1)
	{
		printf("hsh~$ ");
		resu = getline(&line, &len, stdin);
		if (resu == -1)
		{
			printf("\n");
			break;
		}
		strtoken(command, line);
		execution(command, 0);
	}
	free(line);
	free(command);
	return (0);
}
