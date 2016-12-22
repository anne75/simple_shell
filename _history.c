#include "shell.h"

/**
 * _history - output history into STDOUT_FILENO
 * @args: arguments
 * @enva: environment array
 * @pathl: path linked list
 * @histl: history linked list
 * Return: 0 for success
 */
int _history(char **args, char ***enva, node_t **pathl, node_t **histl)
{
	(void) args;
	(void) enva;
	(void) pathl;

	_history_out(histl, STDOUT_FILENO);
	return (0);
}
