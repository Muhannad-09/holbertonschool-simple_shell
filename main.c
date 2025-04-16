#include "shell.h"

/**
 * main - entry point for the shell
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success, or error code
 */
int main(int ac, char **av)
{
	info_t info = INFO_INIT;

	(void)ac; /* unused */
	return (hsh(&info, av));
}

