#include "shell.h"


#define MAX_COMMAND_LENGTH 100

/**
 * main - Simple shell with 'env' built-in command
 *
 * This program provides a simple shell that allows users to run commands
 * or use the 'env' command to print the current environment.
 *
 * Return: Always 0
 */
void printEnvironment(void)
{
	char input[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("SimpleShell> ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if (strlen(input) == 0)
		{
			continue;
		}
		if (strcmp(input, "env") == 0)
		{
			printEnvironment();
		}
	}
	if (1)
	{
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
		}
		else if (pid == 0)
		{
			if (execlp(input, input, NULL) == -1)
			{
				perror("Exec failed");
				exit(1);
			}
		}
		else
		{
			wait(NULL);
		}
		return;
	}
}
