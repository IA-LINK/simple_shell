#include "shell.h"
/**
 * _getenv - the get env function get the value of environment
 * @name: the name of the enviorment variable
 * Return: A pointer will be return
 */
char *_getenv(const char *name)
{
	int l, len;
	char **env;
	char *value;

	if (!name)
		return (NULL);
	env = environ;
	for (l = 0; env[l]; l++)
	{
		for (len = 0; env[l][len] != '='; len++)
			;
		if (strncmp(name, env[l], len) == 0)
		{
			value = &env[l][len + 1];
			return (value);
		}
	}
	return (NULL);
}
