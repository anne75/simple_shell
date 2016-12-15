#include "shell.h"

/**
 * _printenv - prints the environment
 * @envl: linked list of environment
 *
 */
void _printenv(node_t *envl)
{
	if (!envl)
		return;

	while (envl != NULL)
	{
		write(STDOUT_FILENO, envl->name, _strlen(envl->name));
		write(STDOUT_FILENO, "\n", 1);
		envl = envl->next;
	}
}
