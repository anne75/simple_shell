#include "shell.h"


int _exit_(char **enva, node_t **pathl, node_t **histl)
{
	printf("going to write out history\n");
	_history_write(histl);
	printf("GOING TO FREE enva\n");
	free_enva(enva);
	free_list(*pathl);
	free_list(*histl);
	exit(0);
}
