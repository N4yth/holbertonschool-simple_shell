#include "simpleShell.h"

/**
 *envBuiltin - prints the current environment
 *
 *Return: always 0
 */
int envBuiltin(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
