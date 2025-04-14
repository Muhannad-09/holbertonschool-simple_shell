#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>  /* For waitpid */

extern char **environ;  /* Declare environ to access the environment */

#define BUFFER_SIZE 1024

/**
 * main - simple shell interpreter
 *
 * Return: Always 0.
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t nread;
	char *token;
	char *argv[2];  /* We only need one word commands, so we use size 2 */
	pid_t pid;
	int status;

	/* Infinite loop to keep the shell running */
	while (1)
	{
		/* Display prompt only if input is from terminal (not pipe) */
		if (isatty(fileno(stdin))) {
			printf("#cisfun$ ");
			fflush(stdout);
		}

		/* Read user input */
		nread = getline(&input, &len, stdin);

		/* Handle EOF (Ctrl+D) */
		if (nread == -1)
		{
			printf("\n");
			break;  /* Exit the shell */
		}

		/* Remove trailing newline character */
		input[strcspn(input, "\n")] = '\0';

		/* Tokenize the input to get the command */
		token = strtok(input, " ");
		if (token != NULL)
		{
			/* Prepare the argv array */
			argv[0] = token;
			argv[1] = NULL;  /* No arguments, just the command */
			
			/* Fork a new process to execute the command */
			pid = fork();
			if (pid == -1) /* Error in forking */
			{
				perror("Error: ");
				exit(EXIT_FAILURE);
			}

			if (pid == 0) /* Child process */
			{
				if (execve(argv[0], argv, environ) == -1) /* Execute the command */
				{
					perror(argv[0]); /* Command not found */
					exit(EXIT_FAILURE);
				}
			}
			else /* Parent process */
			{
				waitpid(pid, &status, 0); /* Wait for the child process to finish */
			}
		}
	}

	/* Clean up and exit */
	free(input);
	return 0;
}

