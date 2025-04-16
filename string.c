#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int len = 0;
	while (s[len] != '\0')
		len++;
	return len;
}

/**
 * _strcpy - copies a string to another
 * @dest: the destination string
 * @src: the source string
 * Return: the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination string
 * @src: the string to append to dest
 * Return: the concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0') {
		i++;
	}
	while (src[j] != '\0') {
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return dest;
}

/**
 * _strncmp - compares two strings up to n characters
 * @s1: the first string
 * @s2: the second string
 * @n: the number of characters to compare
 * Return: 0 if the strings are equal, a non-zero value otherwise
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && *s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return (n + 1 == 0) ? 0 : (*s1 - *s2);
}

