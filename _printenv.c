#include "shell.h"

/**
 * _printenv - prints the environment
 * @envl: linked list of environment
 *
 */
void _printenv(char **enva)
{
	int i;

	if (!enva)
		return;

	i = 0;
	while (enva[i] != NULL)
	{
		write(STDOUT_FILENO, enva[i], _strlen(enva[i]));
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
}
