#include "shell.h"

/**
 * _exit_ - function that is called when user tries to exit shell
 * @args: args received with the function
 * @env: environmental variables
 * @pathl: linked list for path
 * @histl: linked list for history
 * Return: 0;
 */
int _exit_(char **args, char ***env, node_t **pathl, node_t **histl)
{
	int i;
	char **enva;

	enva = *env;
	i = 0;
	_history_write(histl);
	free_strtow(enva);
	free_list(*pathl);
	free_list(*histl);
	if (args != NULL)
	{
		if (args[1] != NULL)
		{
			i = _atoi(args[1]);
		}
		free_strtow(args);
	}
	exit(i);
	return (0);
}
