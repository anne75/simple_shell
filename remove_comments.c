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
	int i, hashindex;

	i = 0;

	hashindex = _strcspn(line, "#");
	if (hashindex <= 0)
	{
		free(line);
		return (NULL);
	}

	good = malloc(sizeof(char) * (hashindex + 1));
	if (good == NULL)
		return (NULL);
	good = _memcpy(good, line, hashindex)
		good[hashindex] = '\0';
	free(line)
	return (good);
}
