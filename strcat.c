#include "shell.h"

/**
 * _strcat - function that concatenate two strings
 * @dest: char string to be concatenated
 * @src: chara string
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int l = 0;
	int f = 0;

	while (dest[l] != '\0')
		l++;
	while (src[f] != '\0')
	{
		dest[l] = src[f];
		l++;
		f++;
	}
	dest[l] = '\0';
	return (dest);
}
