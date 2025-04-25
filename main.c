#include "simpleShell.h"

/**
 * main - Entry point
 *
 *Return: always 0
 */
int main(void)
{
	int resu = 0, exe_resu = 0, find_error;
	size_t len = 0;
	char *line = "";
	char *command[4096] = {""};

	command[0] = malloc(255);
	if (command[0] == NULL)
		return (0);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("hsh~$ "); /* when the shell is non interactive */
		resu = getline(&line, &len, stdin);

		printf("Received %s, resu = %i, len=%li", line, resu, len);
		if (resu == -1) /* ctrl D handle*/
			break;
		if (strtoken(command, line, " ")) /* builtin function tokenize the line */
			break;
		find_error = findExec(command);
		if (find_error == 0) /* when error is detected in findExec */
		{
			if (isatty(STDIN_FILENO))
				printf("./hsh: no such file or directory\n");
			free(line);
			free(command[0]);
			exit(127);
		}
		else if (find_error == -1) /* when the command exit is call */
			break;
		else if (find_error != 2) /* if = 2 the command already executed */
			exe_resu = execution(command);
	}
	free(command[0]);
	free(line);
	exit(exe_resu);
}
