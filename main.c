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
	return (0);
}
