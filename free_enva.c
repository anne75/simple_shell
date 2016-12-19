#include "shell.h"

/**
 * free_enva - free the environ as an array
 * @enva: environ in array
 *
 * Return: 0
 */
int free_enva(char **enva)
{
	int i;

	for (i = 0; enva[i]; ++i)
		free(enva[i]);
	free(enva);
	return (0);
}
