#include "simpleShell.h"


/**
 *findExec - Handles the paths
 *@command: specifies the location of a directory or a file
 *Return: always 0
 */
int findExec(char **command)
{
	char fullPath[1024];
	char *pathEnv = myGetEnv("PATH");
	char *pathCpy, *dir;

	pathCpy = strdup(pathEnv);
	if (pathCpy == NULL)
		return (0);

	dir = strtok(pathCpy, ":");
	while (dir != NULL)
	{
		sprintf(fullPath, "%s/%s", dir, command[0]);

		if (access(fullPath, X_OK) == 0)
		{
			command[0] = strdup(fullPath);
			free(pathCpy);
			return (1);
		}

		dir = strtok(NULL, ":");
	}

	free(pathCpy);
	return (1);
}
