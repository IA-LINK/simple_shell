#include "shell.h"

int main(void)
{
	char input[MAX_INPUT_SIZE];
	pid_t pid;

	while (1)
	{
		printf("simple_shell$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			printf("\n");
			break;
		}
		input[strlen(input) - 1] = '\0';
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
		}
		else if (pid == 0)
		{
			execlp(input, input, NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);

			if (WIFEXITED(status))
			{
				printf("Child process exited with status %d\n", WEXITSTATUS(status));
			}
			else if (WIFSIGNALED(status))
			{
				printf("Child process terminated by signal %d\n", WTERMSIG(status));
			}
		}
	}
	return (0);
}
