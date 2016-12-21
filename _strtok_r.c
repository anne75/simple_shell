#include "shell.h"

/**
 * _strtok_r - returns a bit of a line
 * @result: where to put the result
 * @line: line to extract part from, always malloc'ed
 * @delim: string of all delimeters to chop the line with
 * @remain: the rest of the line to consider, it is always malloc'd
 * Each time I get out I free the line and malloc the remain if need be
 * It is necessary to obtain line through a previous malloc
 * Return: a pointer to the part of the line to consider
 */
char *_strtok_r(char **result, char *line, char *delim, char **remain)
{
	int index1, index2;
/*	printf("_strtok conditions %i %s\n", !result, *remain);*/
	if (!result || !remain)
		return (NULL);

	if (line == NULL)
		line = *remain;

	index1 = _strspn(line, delim); /*get rid of junk in the beginning*/

	index2 = _strcspn(line + index1, delim);
/*return of end of line or junk*/
	if (*(line + index1 + index2) && *(line + index1 + index2 + 1))
/*I have not reached the end of the line*/
	{
		*remain = line + index1 + index2 + 1;
	}
	else
	{
		*remain = NULL;
	}
	*result = malloc(sizeof(char) * (index2 + 2));
	*result = _memcpy(*result, line + index1, index2);
	(*result)[index2] = '\0';
	return (*result);
}
