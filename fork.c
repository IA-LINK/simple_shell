#include "shell.h"

/**
 * main - Demonstrate process creation and PID retrieval
 *
 * This program creates a child process using fork() and displays
 * the process IDs of the parent and child processes.
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);

	if (child_pid == 0)
	{
		printf("(%u) Nooooooooo!\n", my_pid);
	}
	else
	{
		printf("(%u) %u, I am your father\n", my_pid, child_pid);
	}
	return (0);
}
