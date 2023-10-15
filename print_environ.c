#include "shell.h"

/**
 * print_environ - Print the environment variables.
 *
 * This function prints the environment variables to the standard output, with
 * each variable followed by a newline character.
 */
void print_environ(void)
{
	int j;
	char **env = environ;

	for (j = 0; env[j]; j++)
	{
		/* Print each environment variable */
		write(STDOUT_FILENO, env[j], _strlen(env[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
