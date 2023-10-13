#include "shell.h"

/**
 * main - Create child processes to execute 'ls -l /tmp'
 *
 * This program creates 5 child processes, each executing
 * the 'ls -l /tmp' command,
 * and waits for each child to exit before creating the next one.
 *
 * Return: 0 on success, or exit code on failure
 */
int main(void)
{
	int num_children = 5;
	int i;

	for (i = 0; i < num_children; i++)
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			printf("Child %d (PID %d) executing ls -l /tmp:\n", i, getpid());
			execlp("ls", "ls", "-l", "/tmp", NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			waitpid(child_pid, &status, 0);

			if (WIFEXITED(status))
			{
				printf("Child %d (PID %d) exited with status %d\n", i, child_pid, WEXITSTATUS(status));
			}
			else
			{
				printf("Child %d (PID %d) exited abnormally\n", i, child_pid);
			}
		}
	}
	return (0);
}
