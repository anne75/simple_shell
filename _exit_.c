#include "shell.h"


int _exit_(char **enva, node_t **pathl, node_t **histl, char **args)
{
	printf("going to write out history\n");
	_history_write(histl);
	printf("GOING TO FREE enva\n");
	free_enva(enva);
	free_list(*pathl);
	free_list(*histl);
	if (args != NULL)
		free_strtow(args);
	exit(0);
}
