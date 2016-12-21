#include "shell.h"

/**
 * _unsetenv - unset variable from environment
 * @name: name of variable
 * @enva: array of environ
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name, char **enva)
{
	int i;
	char **tmp;

	i = 0;
	while (enva[i] != NULL)
	{
		if (check_first(enva[i], name))
		{
			free(enva[i]);
			for (tmp = &enva[i];; ++tmp)
			{
				*tmp = *(tmp + 1);
				if (!*tmp)/*true for NULL*/
					break;
			}
		}
		++i;
	}
	*tmp = NULL;
	return (0);
}

/**
 * _unsetenv_help - helper function to unsetenv due to bi_t
 * @args: argument array
 * @enva: environment array
 * @pathl: path linked list
 * @histl: history linked list
 * Return: 0 for success
 */
int _unsetenv_help(char **args, char ***enva, node_t **pathl, node_t **histl)
{
	char *name;
	(void) pathl;
	(void) histl;

	name = args[1];
	_unsetenv(name, *enva);
	return (0);
}
