#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string
 *
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	if (!s)
		return (0);

	while (*s++)
		len++;

	return (len);
}

/**
 * _strcpy - Copies a string
 * @dest: Destination buffer
 * @src: Source string
 *
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == NULL)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - Concatenates two strings
 * @dest: First string and result buffer
 * @src: Second string to append
 *
 * Return: Pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';

	return (ret);
}

