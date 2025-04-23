#include "simpleShell.h"

/**
 *envBuiltin - prints the current environment
 *@environ: environment to print
 *Return: always 0
 */
int envBuiltin(char **environ)
{
	int i = 0;

	printf("env");

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}
