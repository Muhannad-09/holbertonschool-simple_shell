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
 * read_line - Reads input from user
 *
 * Return: Pointer to input line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		free(line);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}
	line[strcspn(line, "\n")] = '\0';
	return (line);
}

/**
 * execute_command - Forks and executes a command
 * @line: The command to execute
 */
void execute_command(char *line)
{
	pid_t pid;
	char *argv[2];

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		argv[0] = line;
		argv[1] = NULL;
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
			break;
		execute_command(line);
		free(line);
	}

	return (0);
}
