#include "shell.h"

/**
 * promp - Display the shell prompt.
 *
 * This function displays the shell prompt ('$ ') to the standard output if the
 * input is being read from a terminal. It flushes the output buffer to ensure
 * the promp is immediately visible.
 */
void promp(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
}
