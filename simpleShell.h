#ifndef SIMPLESHELL
#define SIMPLESHELL

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char **strtoken(char **command, char *line);
int execution(char **command, int error);

#endif
