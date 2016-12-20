#include "shell.h"
#include <stdio.h>


/**
 * prompt - function that will output prompt and read input
 * @remainder: first parameter
 * @enva: environmental 2D array
 * @pathl: linked list for path
 * @histl: linked list for history
 * Return: string read from user
 */
char *prompt(char **remainder, char **enva, node_t *pathl, node_t *histl)
{
	ssize_t nline;
	char *line;
	char *no_comments;
	write(1, "$ ", 2);

/*	printf("%s %i before call remainder is %s\n", __FILE__, __LINE__, *remainder);*/
	nline = _getlinewithbuffer(&line, remainder, STDIN_FILENO);
/*	printf("%s %i after call remainder is %s\n", __FILE__, __LINE__, *remainder);*/


	if (nline <= 0)
	{
		printf("prompt: _getline did not work or EOF\n");
		free(line);
		printf("freeline in prompt\n");
		_exit_(enva, &pathl, &histl, NULL);
		return (NULL);
	}

	no_comments = remove_comments(line);

	return (no_comments);
}
