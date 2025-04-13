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

#endif /* MAIN_H */
