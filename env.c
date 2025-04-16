#include "shell.h"

/**
 * _setenv - initializes a new environment variable, or modifies an existing one
 * @info: Structure containing potential arguments.
 * @name: Name of the environment variable.
 * @value: Value of the environment variable.
 * Return: 0 on success, 1 on failure
 */
int _setenv(info_t *info, char *name, char *value)
{
	list_t *node;
	char *env_str;

	if (!name || !value)
		return (1);

	env_str = malloc(_strlen(name) + _strlen(value) + 2); /* Name=Value\0 */
	if (!env_str)
		return (1);

	_strcpy(env_str, name);
	_strcat(env_str, "=");
	_strcat(env_str, value);

	node = info->env;
	while (node)
	{
		if (_strncmp(node->str, name, _strlen(name)) == 0)
		{
			free(node->str);
			node->str = env_str;
			return (0);
		}
		node = node->next;
	}

	add_node_end(&(info->env), env_str, 0); /* Add to end of env list */
	return (0);
}

/**
 * _unsetenv - removes an environment variable
 * @info: Structure containing potential arguments.
 * @name: Name of the environment variable.
 * Return: 0 on success, 1 on failure
 */
int _unsetenv(info_t *info, char *name)
{
	list_t *node = info->env;
	list_t *prev = NULL;

	if (!name)
		return (1);

	while (node)
	{
		if (_strncmp(node->str, name, _strlen(name)) == 0)
		{
			if (prev)
				prev->next = node->next;
			else
				info->env = node->next;

			free(node->str);
			free(node);
			return (0);
		}
		prev = node;
		node = node->next;
	}

	return (1);
}

