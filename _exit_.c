#include "shell.h"

/**
 * _exit_ - function that is called when user tries to exit shell
 * @enva: environmental variables
 * @pathl: linked list for path
 * @histl: linked list for history
 * @args: args received with the function
 * Return: 0;
 */
int _exit_(char **enva, node_t **pathl, node_t **histl, char **args)
{
	int i;

	i = 0;
	printf("going to write out history\n");
	_history_write(histl);
	printf("GOING TO FREE enva\n");
	free_strtow(enva);
	free_list(*pathl);
	free_list(*histl);
	if (args != NULL)
	{
		if (args[1] != NULL)
		{
			i = _atoi(args[1]);
		}
		printf("%s FREE ARGS\n", __FILE__);
		free_strtow(args);
	}
	exit(i);
	return (0);
}
