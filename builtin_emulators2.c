#include "shell.h"

/**
 * _myhistory - displays the history list
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list_str(info->history);
	return (0);
}

/**
 * _myalias - mimics the alias builtin (not implemented)
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	(void)info;
	return (0);
}

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
