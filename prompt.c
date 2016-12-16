#include "shell.h"
#include <stdio.h>


/**
 * main - read a line
 *
 * Return: number of characters read
 */
char *prompt(void)
{
	ssize_t nline;
	size_t length;
	char *line;
/*	int i;*/

	length = LINE_LENGTH;
/*I have to use malloc*/
	printf("%s %i malloc\n", __FILE__, __LINE__);
	line = malloc(sizeof(char) * length);
	if (line == NULL)
		return (NULL);
	write(1, "$ ", 2);
	nline = _getline(&line, &length, STDIN_FILENO);
/*	nline = getline(&line, &length, stdin);*/
/*	printf("Prompt - prints the line in ascii digits\n");
	for (i = 0; i < nline; ++i)
		printf("%d-", line[i]);
	puts("");
*/	if (nline == -1)
	{
		printf("prompt: _getline did not work, or EOF\n");
		free(line);
		printf("freeline in prompt\n");
		exit(1);
		printf("prompt should not be here\n");
		return (NULL);
	}
	line[nline -1] = '\0'; /*get rid of newline*/
	return (line);
}
