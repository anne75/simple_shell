#include "shell.h"

/* in this file, the function to get the executable from the name
 * given in the command line
 */

/**
 * what_path - get executable from name
 * @name: name of the command passed inline
 * @pathl: linked list of the path
 * the function loops throught the PATH, transformed into a linked list
 * and stops when it finds a match, otherwise returns NULL
 */
char *what_path(char *name, node_t *pathl)
{
	int length_path, length_name;
	char *fullname;
	struct stat st;

	if (_strchr(name, '/') != NULL)
		return (_strdup(name));
	length_name = _strlen(name);

/*	printf("_which %i\n", __LINE__);*/
	while (pathl != NULL)
	{
		length_path = _strlen(pathl->name);
		fullname = malloc(sizeof(char) * (length_path + length_name + 2));
		if (fullname == NULL)
			return (NULL);
		_memcpy(fullname, pathl->name, length_path);
		fullname[length_path] = '/';
		_memcpy(fullname + length_path + 1, name, length_name);
		fullname[length_name + length_path + 1] = '\0';
/*		printf("control which %s\n", fullname);*/
		if (stat(fullname, &st) == 0)
			return (fullname);
		pathl = pathl->next;
	}
	return (NULL);
}
