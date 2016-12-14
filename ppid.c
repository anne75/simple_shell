#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t parent_pid;

	parent_pid = getppid();
	printf("I am executing ppid %u\n", parent_pid);
	return (0);
}
