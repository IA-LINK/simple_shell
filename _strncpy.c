#include "shell.h"
/**
 * _strncpy - copies string
 * @dest: string 1 value
 * @src: string 2 value
 * @n: size
 *
 * Return: dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int l;

	for (l = 0; l < n && src[l] != '\0'; l++)
	{
		dest[l] = src[l];
	}

	for (; l < n; l++)
	{
		dest[l] = '\0';
	}

	return (dest);
}
