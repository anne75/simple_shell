#include "shell.h"

/*this file builds the array of built-ins*/
#define total 9
/**
 * bi_function - makes an array containing all built-ins info
 * @args: arguments of command
 * @enva: array of environment variables
 * @pathl: linked list of paths
 * @histl: linked list of history
 * scans the array of built-ins, return the right function to execute ro NULL
 * Return: result of function or 101
 */

int bi_function(char **args, char ***enva, node_t **pathl, node_t **histl)
{
	int i;
	char *array[total]  = {"exit", "env", "getenv", "setenv", "unsetenv",
			       "cd", "help", "history", "bad"};

	if (!args || !*args || !args[0])
		return (101);
	i = 0;
	while (i < total)
	{
		if (_strcmp(args[0], array[i]) == 0)
			break;
		++i;
	}
	printf("%s %i\n", __FILE__, __LINE__);
	if (i == 0)
		return (_exit_(*enva, pathl, histl, args));
	if (i == 1)
	{
		_printenv(*enva);
		return (0);
	}
	if (i == 2)
	{
		printf("%s %i\n", __FILE__, __LINE__);
		return (bi_getenv(args[1], *enva));
	}
	if (i == 3)
	{
		if (args[1] != NULL)
			return (_setenv(args[1], args[2], 1, enva));
		else
			return (0);
	}
	if (i == 4)
		return (_unsetenv(args[1], *enva));
	if (i == 5)
		return (_cd(args[1], *enva));
	if (i == 6)
		return (_help(args[1]));
	if (i == 7)
		return (_history(histl));
	return (101);
}
