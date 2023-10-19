#include "shell.h"
/**
 * strlen_const - calculates the length a string
 * @s: pointer to the string input
 *
 * Return: length of string
 */
int strlen_const(const char *s)
{
	int j = 0;

	while (s[j] != '\0')
	{
		j++;
	}
	return (1);
}
/**
 * strdup - create a dup
 *
 * this function allocates memory for new string
 * @src: pointer to the source string
 * Return: point to the newly allocated
 */
char *my_strdup(const char *src)
{
	int length, i;
	char *dst;

	if (src == NULL)
		return (NULL);
	length = strlen_const(src);
	if (length < 0)
		return (NULL);

	length++;
	dst = malloc((length) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
		dst[i] = src[i];
	dst[i - 1] = '\0';
	return (dst);
}
