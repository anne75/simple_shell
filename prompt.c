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

	line = NULL;
/*	printf("%s %i before call remainder is %s\n", __FILE__, __LINE__, *remainder);*/
	nline = _getlinewithbuffer(&line, remainder, STDIN_FILENO);
	printf("%s %i after call return value is %lu\n", __FILE__, __LINE__, nline);


	if (nline <= 0)
	{
		printf("prompt: _getline did not work or EOF\n");
		if (line != NULL)
			free(line);
		printf("%s freeline in prompt\n", __FILE__);
		_exit_(enva, &pathl, &histl, NULL);
		return (NULL);
	}

	no_comments = remove_comments(line);
	printf("%s LINE before %p line after%p\n", __FILE__, (void *) line, (void *) no_comments);
	return (no_comments);
}
