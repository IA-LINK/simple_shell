#include "shell.h"

int main (void)
{
	pid_t parent_pid =  getpid();
	printf("parent process PID: %d\n", parent_pid);

	return (0);
}
