#include "shell.h"

/**
 * _strtrim - Trim leading and trailing whitespace from a string.
 * @c: The string to trim.
 * Return: A pointer to the trimmed string.
 */
char *_strtrim(char *k)
{
	char *end;

	while (*k && (*k == ' ' || *k == '\t' || *k == '\n'))
	{
		k++;
	}

	if (*k == '\0')
	{
		return (k); /* return if the entire string is whitespace */
	}

	/* move end pointer back to remove trailing whitespace */
	end = k + strlen(k) - 1;
	while (end > k && (*end == ' ' || *end == '\t' || *end == '\n'))
	{
		end--;
	}
	*(end + 1) = '\0'; /* null-terminate the trimmed string */

	return (k); /* return a pointer to the trimmed string */
}
