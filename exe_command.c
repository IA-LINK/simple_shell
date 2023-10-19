#include "shell.h"
/**
 * _execommand - command with argument to be executed
 * @command_with_args: the command with its argument
 * Return: always return 0 on sucess
 */
int _execommand(char *command_with_args)
{
	pid_t child_pid;
	int status, arg_count = 0;
	char *token, *args[MAX_INPUT_LEN / 2 + 2];

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0)
	{
		token = strtok(command_with_args, " ");
		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		_execute_childprocess(args[0], args);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
