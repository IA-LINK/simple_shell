#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @prmChar: The character to print
 *
 * Return: On success 1.
 * On error, -1 is reurned, and errno is set appropriately
 */
int _putchar(char prmChar)
{
	return (write(STDIN_FILENO, &prmChar, 1));
}
