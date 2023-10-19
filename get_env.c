#include "shell.h"

/**
 * get_env - the get env function gets the value of an environment variable
 * @name: the name of the environment variable
 * Return: A pointer will be returned
 */
char *my_getenv(const char *name)
{
	int i, len;
	char **env;
	char *value;

	if (!name)
		return (NULL);
	env = environ;
	for (i = 0; env[i]; i++)
	{
		for (len = 0; env[i][len] != '='; len++)
			;
		if (strncmp(name, env[i], len) == 0)
		{
			value = &env[i][len + 1];
			return (value);
		}
	}
	return (NULL);
}
