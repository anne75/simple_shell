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
	bi_t array[] = {
		{"exit",
		 "exit [status] - Exit the shell",
		 _exit_},
		{"env",
		 "env - Print environment variables\n",
		 _printenv},
		{"getenv",
		 "getenv VARIABLE - Return value of variable",
		 bi_getenv},
		{"setenv",
		 "setenv VARIABLE VALUE [0] - Create or modify environment variable",
		 _setenv_help},
		{"unsetenv",
		 "unsetenv VARIABLE - Remove environment variable",
		 _unsetenv_help},
		{"cd",
		 "cd [DIRECTORY] - Change directory to DIRECTORY or home",
		 _cd},
		{"help",
		 "help [BUILTIN] - Displays information about BUILTIN or all",
		 _help},
		{"history",
		 "history - Displays list of past commands",
		 _history},
		{NULL, NULL, NULL}
	};
	int i;

	if (!args || !*args || !args[0])
		return (101);
	i = 0;
	while (array[i].name != NULL)
	{
		if (_strcmp(args[0], array[i].name) == 0)
			return (array[i].fp(args, enva, pathl, histl));
		++i;
	}
	return (101);
}
