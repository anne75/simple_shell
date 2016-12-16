#include "shell.h"

void sig_kill(int sig)
{
	if (sig == SIGINT)
	{
		printf("ending current process with exit code 0\n");
		_exit(0);
	}
}

void set_to_kill(void)
{
	if (signal(SIGINT, sig_kill) == SIG_ERR)
	{
		printf("failed to change ctrl+c to kill, abort\n");
		exit(98);
	}
}


void sig_catch(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

void set_to_catch(void)
{
	if (signal(SIGINT, sig_catch) == SIG_ERR)
	{
		printf("failed to change ctrl+c to catch, abort\n");
		exit(98);
	}
}
