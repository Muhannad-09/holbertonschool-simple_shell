#include "shell.h"

/**
 * find_path - finds a command in the directories listed in PATH
 * @info: shell information (unused for now)
 * @pathstr: PATH environment variable
 * @cmd: command to search for
 *
 * Return: the full path of the command, or NULL if not found
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	char *path_copy, *dir, *full_path;
	struct stat st;

	(void)info; /* Suppress unused parameter warning */

	if (!pathstr || !cmd)
		return (NULL);

	path_copy = strdup(pathstr);	/* Copy PATH */
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");

	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);  /* +2 for '/' and '\0' */
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (stat(full_path, &st) == 0)
		{
			free(path_copy);
			return (full_path);	/* Found command */
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);	/* Command not found */
}

