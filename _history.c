#include "shell.h"

int _history(node_t **histl)
{
	_history_out(histl, STDOUT_FILENO);
	return (0);
}
