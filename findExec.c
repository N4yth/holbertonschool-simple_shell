#include "simpleShell.h"

/**
 *findExec - Handles the paths
 *@path: specifies the location of a directory or a file
 *Return: always 0
 */
int findExec(const char *path)
{
	int i = 0;
	char *pathEnv = getenv("PATH");

	if (pathEnv == NULL)
	{
		printf("Error: PATH environment variable not found.\n");
		return (0);
	}

	for (i = 0; i < *pathEnv; i++)
	{
		while (path)
		{
			printf("%d/%s", path[i], path);
			free(pathEnv);
		}
	}
	return (0);
}
