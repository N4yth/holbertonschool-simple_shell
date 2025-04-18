#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

extern char **environ;

char **strtoken(char **command, char *line, char *separator);
int execution(char **command);
int findExec(char **command);
char *myGetEnv(const char *name);

#endif
