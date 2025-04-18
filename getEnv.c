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
	int len, result, i;

	for (i = 0 ; environ[i] ; i++)
	{
		result = strncmp(name, environ[i], strlen(name));
		if (result == 0)
		{
			pathCpy = malloc(strlen(environ[i]));
			if (pathCpy == NULL)
				return (NULL);
			strcpy(pathCpy, environ[i]);
			len = strlen(name) + 1;
			while (len--)
				pathCpy++;
			return (pathCpy);
		}
	}
	return (NULL);
}
