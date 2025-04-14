#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * print_prompt - Print the shell prompt if interactive
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
}

/**
 * read_line - Read a line from stdin and handle EOF
 *
 * Return: pointer to the read line (dynamically allocated)
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *ptr;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		return (NULL);
	}

	/* Remove newline */
	line[strcspn(line, "\n")] = '\0';

	/* Skip empty lines (spaces only) */
	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	if (*ptr == '\0')
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * execute_command - Tokenizes the input and runs execve
 * @line: full input line from user
 */
void execute_command(char *line)
{
	pid_t pid;
	char *argv[100];
	int i = 0;
	char *token;
	char *copy;

	copy = strdup(line);
	if (copy == NULL)
	{
		perror("strdup");
		return;
	}

	token = strtok(copy, " \t");
	while (token && i < 99)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(copy);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./hsh");
			free(copy);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}

	free(copy);
}

/**
 * main - Shell loop
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line;

	while (1)
	{
		print_prompt();
		line = read_line();
		if (line == NULL)
			continue;
		execute_command(line);
		free(line);
	}
	return (0);
}
