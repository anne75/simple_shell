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
 * @args: arguments to parse
 * @env: environmental array
 * @pathl: path linked list
 * @histl: history linked list
 * Return: 0 on success, -1 on failure
 */
int bi_getenv(char **args, char ***env, node_t **pathl, node_t **histl)
{
	char *res;
	char **enva;
	(void) pathl;
	(void) histl;

	enva = *env;
	res = _getenv(args[1], enva);
	if (!res)
		return (-1);
	write(STDOUT_FILENO, res, _strlen(res));
	write(STDOUT_FILENO, "\n", 1);
/*	free(res);*/
	return (0);
}
