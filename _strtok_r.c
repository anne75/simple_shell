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
	printf("_strtok entry line %s\n", line);
	index1 = _strspn(line, delim); /*get rid of junk in the beginning*/

	index2 = _strcspn(line + index1, delim); /*return of end of line or junk*/
/*	printf("%s the indexes to cut at are %i %i and line%s\n", __FILE__, index1, index2, line);*/
	if (*(line + index1 + index2) && *(line + index1 + index2 + 1)) /*I have not reached the end of the line*/
	{
		*remain = line + index1 + index2 + 1;
		printf("_strtok %i - remain %s\n", __LINE__, *remain);
	}
	else
	{
		*remain = NULL;
		printf("%s Setting remainder to NULL\n", __FILE__);
	}
	*result = malloc(sizeof(char) * (index2 + 2));
	*result = _memcpy(*result, line + index1, index2 + 1);
	(*result)[index2 + 1] = '\0';
	printf("%s %i MALLOC result %s\n", __FILE__, __LINE__, *result);
	return (*result);
}


/* int main(void) */
/* { */

/* 	char *result; */
/* 	char *line, *line1; */
/* 	char *delim; */
/* 	char *remain; */

/* 	result = NULL; */
/* 	remain = NULL; */

/* 	line1 = "\n\n\nthis\nis\na\nline\nhi"; */
/* 	line1 = ""; */
/* 	line = _strdup(line1); */
/* 	delim = "\n"; */

/* 	do { */
/* 		result = _strtok_r(&result, line, delim, &remain); */
/* 		line = NULL; */
/* 		printf("finish 1 turn:%s\n", result); */
/* 	} while (remain != NULL); */

/* 	return (0); */
/* } */
