#include "shell.h"

/**
 * _cd - function to change directory
 * @s: first parameter
 * @envl: environmental linked list
 * Return: 0 for success
 */
int _cd(char *s, char **envl)
{
	char *home;
	int i;
	(void) s;

	printf("ENTER CD\n");
	home =_strdup(_getenv("HOME", envl));
	i = _strlen(home);
	home[i] = '\0';
	printf("successfully get home path\n");
	chdir(home);
	_setenv("PWD", home, 1, &envl);
	printf("LLLLLLLLLLLLLLLLLLLLLLLLLLLLL\n");
//	_printenv(envl);
	printf("HOME IS %s\n", home);
	free(home);
	return (0);
}
