#include "shell.h"

void execute_child_process(char *command, char *args[]);
char *get_path(const char *command);


/**
 * execute - Execute a command with arguments in a child process.
 * @command_with_args: The command with its arguments.
 *
 * This function forks a child process to execute the given command along with
 * its arguments using the execve system call. It handles errors related to
 * forking, executing the command, and accessing the command's executable file.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute(char *command_with_args)
{
	pid_t child_pid;
	int status, arg_count = 0;
	char *tok, *args[MAX_INPUT_SIZE / 2 + 2];

	child_pid = fork();
	if (child_pid == -1) /* child process */
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0)
	{
		/* tokenize commands and its arguments */
		tok = strtok(command_with_args, " ");
		while (tok != NULL)
		{
			args[arg_count++] = tok;
			tok = strtok(NULL, " ");
		}
		args[arg_count] = NULL;
		/* call execute child process command */
		execute_child_process(args[0], args);
	}
	else
	{
		wait(&status);
	}
	return (0);
}

/**
 * execute_child_process - Execute a command in a child process with full path.
 * @command: The command to execute.
 * @args: The arguments for the command.
 *
 * This function executes a command in a child process using the execve system
 * call. It handles errors related to executing the command and accessing the
 * command's executable file.
 */
void execute_child_process(char *command, char *args[])
{
	char *get_path(const char *command);
	char *path = NULL;

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
