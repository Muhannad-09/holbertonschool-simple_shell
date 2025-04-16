#include "shell.h"

/**
 * _setenv - Sets or updates an environment variable
 * @info: Pointer to the info struct
 * @name: The name of the environment variable
 * @value: The value of the environment variable
 *
 * Return: 0 on success, 1 on failure
 */
int _setenv(info_t *info, char *name, char *value)
{
	char *env_str;
	list_t *node;
	char *p;

	if (!name || !value)
		return (1);

	env_str = malloc(_strlen(name) + _strlen(value) + 2);
	if (!env_str)
		return (1);

	_strcpy(env_str, name);
	_strcat(env_str, "=");
	_strcat(env_str, value);

	node = info->env;
	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = env_str;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), env_str, 0);
	free(env_str);
	info->env_changed = 1;
	return (0);
}

/**
 * _unsetenv - Removes an environment variable
 * @info: Pointer to the info struct
 * @name: The name of the environment variable to remove
 *
 * Return: 1 if deleted, 0 otherwise
 */
int _unsetenv(info_t *info, char *name)
{
	list_t *node = info->env;
	list_t *prev = NULL;
	char *p;

	if (!info->env || !name)
		return (0);

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p == '=')
		{
			if (prev)
				prev->next = node->next;
			else
				info->env = node->next;

			free(node->str);
			free(node);
			info->env_changed = 1;
			return (1);
		}
		prev = node;
		node = node->next;
	}
	return (0);
}

/**
 * _erratoi - converts a string to an integer with error checking
 * @s: the string to be converted
 *
 * Return: the converted number if successful, or -1 on error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

