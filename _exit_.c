#include "shell.h"


int _exit_(node_t **envl, node_t **pathl, node_t **histl)
{
	free_list(*envl);
	free_list(*pathl);
	free_list(*histl);
	exit(0);
}
