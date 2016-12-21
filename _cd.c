#include "shell.h"

/**
 * _cd - function to change directory
 * @args: arguments
 * @envl: environmental linked list
 * @pathl: path linked list
 * @histl: history linked list
 * Return: 0 for success
 */
int _cd(char **args, char ***envl, node_t **pathl, node_t **histl)
{
	char *home;
	char *prev;
	(void) pathl;
	(void) histl;

	if (args[1] == NULL)
		home = _strdup(_getenv("HOME", *envl));
	else if (*args[1] == '-')
	{
		if (_getenv("OLDPWD", *envl) != NULL)
			home = _strdup(_getenv("OLDPWD", *envl));
		else
			return (-1);
	}
	else
		home = _strdup(args[1]);
	prev = _strdup(_getenv("PWD", *envl));
	_setenv("OLDPWD", prev, 1, envl);
	chdir(home);
	_setenv("PWD", home, 1, envl);
	free(prev);
	free(home);
	return (0);
}
