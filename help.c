#include "shell.h"

/**
 * _help - help command
 * @args: array of arguments
 * @a: array of built ins
 * Return: 0
 */
int _help(char **args, bi_t *a)
{
	int i;

	if (args[1] == NULL)
	{
		i = 0;
		while (a[i].name != NULL)
		{
			write(STDOUT_FILENO, a[i].help, _strlen(a[i].help));
			write(STDOUT_FILENO, "\n", 1);
			++i;
		}
	}
	else
	{
		i = 0;
		while (a[i].name != NULL)
		{
			if (_strcmp(a[i].name, args[1]) == 0)
			{
				write(STDOUT_FILENO, a[i].help,
				      _strlen(a[i].help));
				write(STDOUT_FILENO, "\n", 1);
			}
			++i;
		}
	}
	return (0);
}

/*bi_t *bi_array(char *name)*/

/*{
	bi_t array[] = {
		{"exit",
		 "exit [status]\nExit the shell\n",
		 exit},
		{"env",
		 "env\nPrint environment variables\n",
		 env},
		{"setenv",
		 "setenv VARIABLE VALUE [0]\nCreate or modify"
		 "environment variable\n",
		 setenv},
		{"unsetenv",
		 "unsetenv  VARIABLE\nRemove environment variable\n",
		 unsetenv},
		{"cd",
		 "cd [DIRECTORY]\nChange directory to DIRECTORY or home\n",
		 cd},
		{"help",
		 "help [BUILTIN]\nDisplays information about BUILTIN or help\n",
		 help},
		{"history",
		 "history\nDisplays list of past commands\n",
		 history},
		NULL
	};

	return (array);
}
*/
