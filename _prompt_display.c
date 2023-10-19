#include "shell.h"

/**
 * _prompt_display - Display the prompt
 */
void _prompt_display(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
}
