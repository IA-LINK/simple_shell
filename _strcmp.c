#include "shell.h"
/**
 * _strcmp - function that compare two string
 * @str3: first string to comp
 * @str4: second string to comp
 * Return: return string
 */
int _strcmp(const char *str3, const char *str4)
{
	while (*str3 != '\0' && *str3 == *str4)
	{
		str3++;
		str4++;
	}
	return (*(unsigned char *)str3 - *(unsigned char *)str4);
}
