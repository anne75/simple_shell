#include "shell.h"

/**
 * _history - output history into STDOUT_FILENO
 * @histl: history linked list
 * Return: 0 for success
 */
int _history(node_t **histl)
{
	_history_out(histl, STDOUT_FILENO);
	return (0);
}
