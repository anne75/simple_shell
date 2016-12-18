#include "shell.h"

/**
 * initialize_shell - initialize all vanlues needed during the session
 * @enva: head of environ list
 * @pathl: head of path list
 * Return: 0 on success, -1 on error
 */
int initialize_shell(char ***enva, node_t **pathl)
{
	node_t *check;

	printf("%s %i\n", __FILE__, __LINE__);
	*enva = env_array();
	if (enva == NULL)
		return (-1);

	*pathl = NULL;
	link_path(pathl, *enva);

	return (0);
}
