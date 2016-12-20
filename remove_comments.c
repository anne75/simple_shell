#include "shell.h"

/**
 * remove_comments - remove everything after #
 * @line: input line
 * Return: a clean line
 */
char *remove_comments(char *line)
{
	char **split;
	char *good;
	int i;

	split = strtow(line, "#");
	if (split == NULL)
		return (NULL);

	good = split[0];
	printf("%s the good stuff %s\n", __FILE__, good);
	i = 1;
	while (split[i] != NULL)
		++i;
	while (--i >= 1)
		free(split[i]);
	free(split);
	return (good);
}
