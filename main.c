#include "simpleShell.h"

/**
 * main - Entry point
 *
 *Return: always 0
 */
int main(void)
{
	int max = 10;
	size_t len;
	char *line;
	char **command;

	while (max)
	{
		printf("hsh(%d)~$ ", max);
		line = malloc(255);
		getline(&line, &len, stdin);
		strtoken(line);
		execution(command, 0);
		max--;
	}

	free(line);
	free(command);
	return (0);
}
