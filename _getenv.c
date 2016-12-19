#include "shell.h"



/**
 * _getenv - simple version of getenv
 * @name: name of variable to find
 * @enva: pointer to environment
 * Return: pointer to value of variable or NULL
 */
char *_getenv(const char *name, char **enva)
{
	int i;

	if (!enva || !name)
		return (NULL);

	i = 0;
	while (enva[i] != NULL)
	{
		if (check_first(enva[i], name))
		{
			return (enva[i] + _strlen(name) + 1);
		}
		++i;
	}
	return (NULL);
}


/**
 * bi_getenv - same function, prints result for built-in
 * @name: name of variable to find
 * @enva: pointer to environment
 * Return: 0 on success, -1 on failure
 */
int bi_getenv(const char *name, char **enva)
{
	char *res;

	res = _getenv(name, enva);
	if (!res)
		return (-1);
	write(STDOUT_FILENO, res, _strlen(res));
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}



