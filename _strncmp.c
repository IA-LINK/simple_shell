#include "shell.h"
/**
 * _strncmp - compares two strings and returns their difference
 * @s1: the first string
 * @s2: the second string
 * @n: number of bytes to compare
 * Return: number of bytes that differ
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t k;

	for (k = 0; k < n; k++)
	{
		if (s1[k] != s2[k])
			return (s1[k] - s2[k]);
		if (s1[k] == '\0')
			return (0);
	}
	return (0);
}
