#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Gives access to the environment for execve */
extern char **environ;

/* Function Prototypes */
void prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);

#endif /* SHELL_H */
