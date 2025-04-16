#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments
 * Return: exits with a given exit status (0) if info->argv[1] is not set
 */
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit argument */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exitcheck;
		return (-2); /* signal to exit */
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mysetenv - sets a new environment variable
 * @info: Structure containing potential arguments
 * Return: 0 on success, 1 on failure
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Usage: setenv VARIABLE VALUE\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (1);
	return (0);
}

/**
 * _myunsetenv - unsets environment variables
 * @info: Structure containing potential arguments
 * Return: 0 on success, 1 on failure
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc < 2)
	{
		_eputs("Usage: unsetenv VARIABLE [VARIABLE...]\n");
		return (1);
	}
	for (i = 1; i < info->argc; i++)
		_unsetenv(info, info->argv[i]);
	return (0);
}

