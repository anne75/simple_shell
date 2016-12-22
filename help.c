#include "shell.h"

/**
 * _help_all - print out all help messages
 * @array: array storing help messages
 * Return: 0 for success
 */
int _help_all(bi_t *array)
{
	int i;

	i = 0;
	while (array[i].name != NULL)
	{
		write(STDOUT_FILENO, array[i].help, _strlen(array[i].help));
		i++;
	}
	return (0);
}

/**
 * _help - help command
 * @args: arguments
 * @enva: environment array
 * @pathl: path linked list
 * @histl: history linked list
 * Return: 0
 */
int _help(char **args, char ***enva, node_t **pathl, node_t **histl)
{
	bi_t array[] = {
		{"exit", "exit [status] - Exit the shell\n", _exit_},
		{"env", "env - Print environment variables\n", _printenv},
		{"getenv", "getenv VARIABLE - Return value of variable\n", bi_getenv},
		{"setenv",
		 "setenv VARIABLE VALUE [0] - Create or modify environment variable\n",
		 _setenv_help},
		{"unsetenv", "unsetenv VARIABLE - Remove environment variable\n",
		 _unsetenv_help},
		{"cd", "cd [DIRECTORY] - Change directory to DIRECTORY or home\n", _cd},
		{"help", "help [BUILTIN] - Displays information about BUILTIN or all\n",
		 _help},
		{"history", "history - Displays list of past commands\n",
		 _history}, {NULL, NULL, NULL}
	};
	int i, j;
	(void) enva; (void) pathl; (void) histl;

	if (!args || !*args || !args[0])
		return (101);
	i = 0;
	if (args[1] == NULL)
		_help_all(array);
	else
	{
		while (array[i].name != NULL)
		{
			if (_strcmp(args[1], array[i].name) == 0)
			{
				j = _strlen(array[i].help);
				write(STDOUT_FILENO, array[i].help, j);
				break;
			}
			i++;
		}
	}
	if (i >= 8)
		_help_all(array);
	return (0);
}
