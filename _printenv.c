#include "shell.h"

/**
 * _printenv - prints the environment
 * @enva: linked list of environment
 * Return: 0
 */
int _printenv(char **enva)
{
	int i;

	if (!enva)
		return (0);
	printf("enter printenv\n");
	i = 0;
	while (enva[i] != NULL)
	{
		printf("enter while loop\n");
		write(STDOUT_FILENO, enva[i], _strlen(enva[i]));
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
	return (0);
}
