#include "shell.h"
#include <stdio.h>


/**
 * prompt - function that will output prompt and read input
 * @buf: buffer to store values
 * @rem: first parameter
 * @enva: environmental 2D array
 * @pathl: linked list for path
 * @histl: linked list for history
 * @e_o_f: end of file flag
 * Return: string read from user
 */
char *prompt(char **buf, char **rem, char **enva,
	     node_t *pathl, node_t *histl, int *e_o_f)
{
	ssize_t nline;
	char *line;
	char *no_comments;

	line = NULL;
	nline = _getlinewithbuffer(buf, &line, rem, STDIN_FILENO, e_o_f);
	if (nline <= 0)
	{
		if (line != NULL)
			free(line);
		_exit_(NULL, &enva, &pathl, &histl);
		return (NULL);
	}
	no_comments = remove_comments(line);
	return (no_comments);
}
