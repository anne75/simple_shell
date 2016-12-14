#include "shell.h"

/* in this file, the function to get the exectuable from the name
 * given in the command line
 */

/**
 * _which - get executable from name
 * @name: name of the command passed inline
 * the function loops throught the PATH, transformed into a linked list
 * and stops when it finds a match, otherwise returns NULL
 */
char *_which(char *name)
{
	int length_path, length_name;
	char *fullname;
	node_t *head;
	struct stat st;

	if (_strchr(name, '/') != NULL)
		return (NULL);
	length_name = _strlen(name);
	head = NULL;
	link_path(&head); /*use function in environment.c*/
/*	printf("_which %i\n", __LINE__);*/
	while (head != NULL)
	{
		length_path = _strlen(head->name);
		fullname = malloc(sizeof(char) * (length_path + length_name + 2));
		if (fullname == NULL)
			return (NULL);
		_memcpy(fullname, head->name, length_path);
		fullname[length_path] = '/';
		_memcpy(fullname + length_path + 1, name, length_name);
		fullname[length_name + length_path + 1] = '\0';
/*		printf("control which %s\n", fullname);*/
		if (stat(fullname, &st) == 0)
			return (fullname);
		head = head->next;
	}

	return (NULL);
}

/**
 * main - standalone for which function
 * @ac: number of args
 * @av: list of args as strings
 * Return: 0 on success, 1 otherwise
 */
int main(int ac, char **av)
{
	char *result;
	int i, bad;

	if (ac < 2)
		return (1);

	i = 1;
	bad = 0;
	while(i < ac)
	{
		result = _which(av[i]);
		if (result != NULL)
		{
			write(STDOUT_FILENO, result, _strlen(result));
			write(STDOUT_FILENO, "\n", 1);
		}
		else
		{
			bad = 1;
		}
		++i;
	}
	if (bad)
		return (1);
	return (0);
}
