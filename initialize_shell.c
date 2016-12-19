#include "shell.h"

/**
 * initialize_shell - initialize all vanlues needed during the session
 * @enva: head of environ list
 * @pathl: head of path list
 * @histl: head of history
 * @remainder: for use with getline and buffer
 * Return: 0 on success, -1 on error
 */
int initialize_shell(char ***enva, node_t **pathl,
		     node_t **histl, char **remainder)
{
	node_t *check, **check2;

	printf("%s %i\n", __FILE__, __LINE__);
	*enva = env_array();
	if (enva == NULL)
		return (-1);

	*pathl = NULL;
	check  = link_path(pathl, *enva);
	if (check == NULL)
		return (1);
	*histl = NULL;
	check2 = history_init(histl);
	if (check2 == NULL)
		return (1);
	*remainder = NULL;

	return (0);
}
