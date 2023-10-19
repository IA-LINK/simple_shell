#include "shell.h"
/**
 * my_strlen - function to calculate length of a string
 * @str: string to cal
 * Return: return length
 */
size_t my_strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
