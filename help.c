#include "shell.h"

/**
 * _help - help command
 * @s: string input
 * Return: 0
 */
int _help(char *s)
{
	(void) s;
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
