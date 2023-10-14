#include "shell.h"


#define MAX_COMMAND_LENGTH 100

/**
 * main - Super simple shell to run commands with full path (no arguments)
 *
 * This program provides a basic shell that allows users to run commands
 * with their full path but doesn't support command-line arguments.
 *
 * Return: Always 0
 */
int main(void)
{
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("SuperSimpleShell> ");

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) == 0)
		{
			continue;
		}
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
		}
		else if (pid == 0)
		{
			execlp(input, input, NULL);
			perror("Exec failed");
			exit(1);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
