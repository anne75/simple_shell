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
	char *prev;
	int i;

	printf("enter _cd func\n");
	if (args[1] == NULL)
		home = _strdup(_getenv("HOME", envl));
	else if (*args[1] == '-')
	{
		if (!_getenv("OLDPWD", envl))
		{
			printf("OLDPWD not set");
			return (-1);
		}
		home = _strdup(_getenv("OLDPWD", envl));
		printf("HOME IS %s\n", home);
	}
	else
		home = _strdup(args[1]);
	i = _strlen(home);
	home[i] = '\0';
	printf("home is %s\n", home);
	prev = _strdup(_getenv("PWD", envl));
	chdir(home);
	printf("i think i changed it!\n");
	_setenv("OLDPWD", prev, 1, &envl);
	_setenv("PWD", home, 1, &envl);
	free(home);
	return (0);
}
