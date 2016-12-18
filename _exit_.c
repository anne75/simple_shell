#include "shell.h"


int _exit_(char **enva, node_t **pathl, node_t **histl)
{
	free_enva(enva);
	free_list(*pathl);
	free_list(*histl);
	exit(0);
}
