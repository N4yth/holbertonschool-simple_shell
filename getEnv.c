#include "simpleShell.h"

/**
 *myGetEnv - retrieve the value of an environment variable
 *@name: string representing the name of the ev to retrieve
 *
 *Return: value of the environment variable or NULL
 */
char *myGetEnv(const char *name)
{
	char *pathCpy;
	int lenName = strlen(name), result, i;

	if (environ == NULL)
		return (NULL);

	for (i = 0 ; environ[i] ; i++)
	{
		result = strncmp(name, environ[i], strlen(name));
		if (result == 0) /* compare name with name of env var name */
		{
			pathCpy = malloc((strlen(environ[i]) + 1) - lenName);
			if (pathCpy == NULL)
				return (NULL);
			strcpy(pathCpy, environ[i] + lenName);
			/* cpy and dont take the name of env var */
			return (pathCpy);
		}
	}
	return (NULL);
}
