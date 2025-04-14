#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * print_prompt - Prints the shell prompt only in interactive mode
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
}

/**
 * read_line - Reads input from user, trims spaces
 *
 * Return: Pointer to valid input line or NULL
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
		free(line);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}

	line[strcspn(line, "\n")] = '\0';

	ptr = line;
	while (*ptr)
	{
		if (*ptr != ' ' && *ptr != '\t')
			break;
		ptr++;
	}

	if (*ptr == '\0')
	{
		free(line);
		return (NULL);
	}

	return (line);
}

/**
 * execute_command - Forks and executes a command with arguments
 * @line: The input line containing the command
 */
void execute_command(char *line)
{
	pid_t pid;
	char *argv[100];
	int i = 0;
	char *token;

	token = strtok(line, " \t");
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
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("./hsh");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}

/**
 * main - Entry point of the shell
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
