#include "shell.h"

/**
 * _printenv - prints the environment
 * @args: arguments used
 * @env: linked list of environment
 * @pathl: path linked list
 * @histl: history linked list
 * Return: 0 for success
 */
int _printenv(char **args, char ***env, node_t **pathl, node_t **histl)
{
	int i;
	char **enva;
	(void) args;
	(void) pathl;
	(void) histl;

	enva = *env;
	if (!enva)
		return (-1);
	i = 0;
	while (enva[i] != NULL)
	{
		write(STDOUT_FILENO, enva[i], _strlen(enva[i]));
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
	return (0);
}
