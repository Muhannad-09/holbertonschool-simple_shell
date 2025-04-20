#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: Length of the string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

