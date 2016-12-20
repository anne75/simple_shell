#include "shell.h"

/**
 * _cd - function to change directory
 * @s: first parameter
 * @envl: environmental linked list
 * Return: 0 for success
 */
int _cd(char **args, char **envl)
{
	char *home;
	char temp[1024];
	int i;

	if (*args[1] == '-')
	{
		if (!_getenv("OLDPWD", envl))
		{
			printf("OLDPWD not set");
			return (-1);
		}
		home = _strdup(_getenv("OLDPWD", envl));
		printf("HOME IS %s\n", home);
	}
	else if (args[1] != NULL)
		home = _strdup(args[1]);
	else
		home = _strdup(_getenv("HOME", envl));
	i = _strlen(home);
	home[i] = '\0';
	printf("home is %s\n", home);
	chdir(home);
	printf("i think i changed it!\n");
	getcwd(temp, sizeof(temp));
	_setenv("OLDPWD", temp, 1, &envl);
	_setenv("PWD", home, 1, &envl);
	free(home);
	return (0);
}
