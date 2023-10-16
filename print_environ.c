#include "shell.h"

#include <stdio.h>
#include <unistd.h>

/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * print_environ - Print the environment variables.
 *
 * This function prints the environment variables to the standard output,
 * with each variable followed by a newline character.
 */
void print_environ(void)
{
	int j;
	char **env = environ;

	for (j = 0; env[j]; j++)
	{
		write(STDOUT_FILENO, env[j], strlen(env[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
