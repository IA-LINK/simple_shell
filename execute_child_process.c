#include "shell.h"
/**
 * _execute_childprocess - excute a command in child process
 * @command: command to execute
 * @args: arguments
 */
void _execute_childprocess(char *command, char *args[])
{
	char *path = _getpath(command);

	if (path != NULL)
	{
		if (execve(path, args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else if (access(command, X_OK) == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("execve");
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		perror("./hsh");
		_exit(EXIT_FAILURE);
	}
}
