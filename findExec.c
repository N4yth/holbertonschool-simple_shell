#include "simpleShell.h"

/**
 *findExec - Handles the paths
 *@command: specifies the location of a directory or a file
 *Return: always 0
 */
int findExec(char **command)
{
	char *pathEnv = myGetEnv("PATH"), *pathCpy, *dir, final_path[255];
	DIR *file;
	struct dirent *entry;

	if (!strcmp(command[0], "exit"))
	{
		free(pathEnv);
		return (-1);
	} else if (!access(command[0], X_OK))
	{
		free(pathEnv);
		return (1);
	} else if (pathEnv == NULL)
	{
		free(pathEnv);
		return (0);
	}
	pathCpy = strdup(pathEnv);
	free(pathEnv);
	for (dir = strtok(pathCpy, ":"); dir != NULL ; dir = strtok(NULL, ":"))
	{
		file = opendir(dir);
		if (file)
		{
			while ((entry = readdir(file)) != NULL)
			{
				if (!strcmp(entry->d_name, command[0]))
				{
					sprintf(final_path, "%s/%s", dir, command[0]);
					strcpy(command[0], final_path);
					closedir(file);
					free(pathCpy);
					return (1);
				}
			}
			closedir(file);
		}
	}
	free(pathCpy);
	return (0);
}
