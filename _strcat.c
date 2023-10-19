#include "shell.h"
/**
 * _strcat - function that concatenate two strings
 * @dest: char string to be concatenated
 * @src: chara string
 * Return: concatenated string
 */
char *my_strcat(char *dest, char *src)
{
	int j = 0;
	int l = 0;

	while (dest[j] != '\0')
		j++;
	while (src[l] != '\0')
	{
		dest[j] = src[l];
		j++;
		l++;
	}
	dest[j] = '\0';
	return (dest);
}
