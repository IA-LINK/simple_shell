#include "shell.h"
/**
 * _strlen_const - calculates the length a string
 * @s: pointer to the string input
 *
 * Return: length of string
 */
int _strlen_const(const char *s)
{
	int l = 0;

	while (s[l] != '\0')
	{
		l++;
	}
	return (1);
}
/**
 * _strdup - create a dup
 *
 * this function allocates memory for new string
 * @src: pointer to the source string
 * Return: point to the newly allocated
 */
char *_strdup(char *src)
{
	int length, d;
	char *dst;

	if (src == NULL)
		return (NULL);
	length = _strlen_const(src);
	if (length < 0)
		return (NULL);

	length++;
	dst = malloc((length) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	for (d = 0; d < length; d++)
		dst[d] = src[d];
	dst[d - 1] = '\0';
	return (dst);
}
