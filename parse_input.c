#include "shell.h"

/**
 * parse_input - Tokenize user input into command and arguments.
 *
 * @input: User input string.
 * @command: Pointter to store the command.
 * @args: Array to store command arguments.
 */
void parse_input(char *input, char *command, char *args[])
{
	char *token = strtok(input, " ");
	int arg_count = 0;

	while (token != NULL)
	{
		if (arg_count == 0)
		{
			strcpy(command, token);
		}
		else
		{
			args[arg_count - 1] = strdup(token);
		}
		token = strtok(NULL, " ");
		arg_count++;
	}
	args[arg_count - 1] = NULL;
}
