#include "shell.h"

int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
		return 1;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return 1;
}
