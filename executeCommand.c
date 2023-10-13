#include "shell.h"

/**
 * main - Entry point for a simple interactive program
 *
 * Return: Always 0;
 */
int main(void)
{
	char command[256];

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			write(STDOUT_FILENO, "&", 2);
			fflush(stdout);

			if (fgets(command, sizeof(command), stdin) == NULL)
			{
				break;
			}
			write(STDOUT_FILENO, "you entered: ", strlen("You entered: "));
			write(STDOUT_FILENO, command, strlen(command));
		}
	}
	return (0);
}
