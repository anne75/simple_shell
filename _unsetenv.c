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
				*tmp = *(tmp + 1);
				if (!*tmp)/*true for NULL*/
					break;
		}
		++i;
	}
	return (0);
}
