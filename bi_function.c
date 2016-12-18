#include "shell.h"

/*this file builds the array of built-ins*/

/**
 * bi_function - makes an array containing all built-ins info
 * @args: arguments of command
 * @envl: linked list of environment variables
 * scans the array of built-ins, return the right function to execute ro NULL
 * Return: result of function or 101
 */
int bi_function(char **args, node_t **envl, node_t **pathl, node_t **histl)
{
	int i;

	char *array[8]  = {
		"exit",
		"env",
		"setenv",
		"unsetenv",
		"cd",
		"help",
		"history",
		"bad"
	};

	if (!args || !*args || !args[0])
		return (101);

	i = 0;
	while (i < 8)
	{
		if ( _strcmp(args[0], array[i]) == 0)
			break;
		++i;
	}
	if (i == 0)
		return (_exit_(envl, pathl, histl));
	if (i == 1)
	{
		_printenv(*envl);
		return (0);
	}
	if (i == 2)
	{
		if (args[1] != NULL)
			return (_setenv(args[1], args[2], 1, envl));
		else
			return (101);
	}
	if (i == 3)
		return (_unsetenv(args[1], envl));
	if (i == 4)
		return (_cd(args[1], *envl));
	if (i == 5)
		return (_help(args[1]));
	if (i == 6)
		return (_history());
	return (101);
}
