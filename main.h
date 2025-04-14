#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void prompt(void);
void execute_command(char *command);

extern char **environ;

void print_prompt(void);
char *read_line(void);
void execute_command(char *line);

#endif /* MAIN_H */
