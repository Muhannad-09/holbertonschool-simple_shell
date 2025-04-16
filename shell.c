#include "shell.h"

/**
 * hsh - main shell loop
 * @info: pointer to the structure containing shell information
 * @av: argument vector
 *
 * Return: 0 on success, or an error code on failure
 */
int hsh(info_t *info, char **av)
{
	ssize_t readn;
	int builtin_ret = 0;

	while (1)
	{
		clear_info(info);

		if (interactive(info))
			_puts("$ ");  /* Display prompt if in interactive mode */
		_eputchar(BUF_FLUSH);  /* Ensure prompt is displayed */

		readn = get_input(info);  /* Get user input */
		if (readn == -1)
		{
			if (interactive(info))
				_puts("\n");
			break;
		}

		set_info(info, av);  /* Set information structure */
		builtin_ret = find_builtin(info);  /* Check if command is a built-in */

		if (builtin_ret == -1)  /* If not a built-in command, find and execute external command */
			find_cmd(info);

		if (builtin_ret == -1)
			fork_cmd(info);  /* If still no match, fork a child process to execute the command */

		free_info(info, 0);  /* Free allocated memory */
	}

	return (0);
}

/**
 * find_builtin - checks if the command is a built-in
 * @info: shell information
 *
 * Return: -1 if not a built-in command, otherwise the return value of the built-in function
 */
int find_builtin(info_t *info)
{
	int i;
	builtin_table builtin[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}  /* End of array */
	};

	for (i = 0; builtin[i].type; i++)
	{
		if (_strcmp(info->argv[0], builtin[i].type) == 0)
			return (builtin[i].func(info));  /* Call the function for the built-in */
	}

	return (-1);  /* Return -1 if not a built-in */
}

/**
 * find_cmd - finds a command from the PATH
 * @info: shell information
 */
void find_cmd(info_t *info)
{
	char *path = NULL;

	path = find_path(info, getenv("PATH"), info->argv[0]);
	if (path)
	{
		if (execve(path, info->argv, info->environ) == -1)
		{
			print_error(info, "not found");
			free(path);
		}
	}
	else
	{
		print_error(info, "not found");
	}
}

/**
 * fork_cmd - forks a child process to execute a command
 * @info: shell information
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(info->argv[0], info->argv, info->environ) == -1)
		{
			print_error(info, "not found");
			exit(127);
		}
	}
	else
	{
		wait(NULL);  /* Wait for child to finish */
	}
}

/**
 * interactive - checks if the shell is in interactive mode
 * @info: shell information
 *
 * Return: 1 if interactive, 0 otherwise
 */
int interactive(info_t *info)
{
	if (isatty(STDIN_FILENO) && info->readfd == 0)
		return (1);
	return (0);
}

/**
 * clear_info - clears the shell information
 * @info: shell information
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
	info->line_count = 0;
	info->err_num = 0;
	info->linecount_flag = 0;
	info->fname = NULL;
	info->env = NULL;
	info->history = NULL;
	info->alias = NULL;
	info->environ = NULL;
	info->env_changed = 0;
	info->status = 0;
	info->cmd_buf = NULL;
	info->cmd_buf_type = 0;
	info->readfd = 0;
	info->histcount = 0;
}

/**
 * set_info - initializes shell info structure
 * @info: pointer to the shell info structure
 * @av: argument vector
 */
void set_info(info_t *info, char **av)
{
	int i;

	info->fname = av[0];
	info->argv = av;
	info->argc = 0;

	for (i = 0; av[i]; i++)
		info->argc++;
}

/**
 * free_info - frees allocated memory in the info structure
 * @info: pointer to the shell info structure
 * @all: flag to free all resources
 */
void free_info(info_t *info, int all)
{
	free(info->argv);
	info->argv = NULL;

	if (all)
	{
		if (info->cmd_buf)
			free(info->cmd_buf);
	}
}

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 *
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - writes a string to stdout
 * @str: string to print
 */
void _puts(char *str)
{
	while (*str)
		_putchar(*str++);
}

/**
 * _eputchar - writes a character to stderr
 * @c: character to print
 *
 * Return: 1 on success, -1 on error
 */
int _eputchar(char c)
{
	return (write(2, &c, 1));
}

/**
 * _eputs - writes a string to stderr
 * @str: string to print
 */
void _eputs(char *str)
{
	while (*str)
		_eputchar(*str++);
}

/**
 * get_input - gets a line of input from the user
 * @info: pointer to the info structure
 *
 * Return: number of characters read
 */
ssize_t get_input(info_t *info)
{
	static char buffer[READ_BUF_SIZE];
	static int i;
	ssize_t readn = 0;
	char *ptr = NULL;
	char *newline = NULL;

	readn = read(info->readfd, buffer, READ_BUF_SIZE);
	if (readn == 0)
		return (0);  /* No input */
	if (readn == -1)
		return (-1);  /* Error reading input */

	ptr = buffer + i;
	newline = strchr(ptr, '\n');  /* Check for newline */
	if (newline)
	{
		*newline = '\0';  /* Null-terminate at newline */
		info->arg = strdup(ptr);
		i = 0;  /* Reset buffer index */
	}
	else
	{
		info->arg = strdup(ptr);  /* No newline, read the whole buffer */
	}

	return (readn);  /* Return the number of characters read */
}

/**
 * print_error - prints error message to stderr
 * @info: pointer to info structure
 * @msg: message to print
 */
void print_error(info_t *info, char *msg)
{
	_eputs(info->fname);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(msg);
	_eputs("\n");
}

