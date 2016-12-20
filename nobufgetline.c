#include "shell.h"

/**
 * fill_buffer - fill buffer with '\0' char
 * @buf: pointer to buffer
 * @size: pointer to size of buffer
 * @c: char to insert at index
 * @index: index at which to enter char
 * since we need to insert '\0' at end of buffer, check we have room
 * or realloc
 */
void fill_buffer(char **buf, size_t *size, char c, size_t index)
{
	char *p;

	if (!buf || !size)
		return; /*should exit really*/
	if (index >= *size - 1) /*I need 2 free spots at this point*/
	{
		printf("realloc buffer\n");
		*buf = _realloc(*buf, *size, *size * 2);
		if (*buf == NULL)
			return;
		*size = *size * 2;
		printf("after realloc %lu,\n", *size);
	}
	p = *buf;
/*	printf("fill_buffer, char is %d index is %lu\n", c, index);*/
	*(p + index) = c;
/*	printf("fill_buffer, assigned %c", *((*buf) + index));*/
}

/**
 * _getline - read a line from standard input
 * @buf: a pointer to a buffer
 * @size: size of buffer
 * @file_strm: input stream
 * Return: number of characters read on success, -1 otherwise
 */
ssize_t _getline(char **buf, size_t *size, int file_strm)
{
	size_t index;
	char c;
	int check_r;

	if (!buf || !size)
		return (-1);
	if (!*buf)
	{
		*size = BUF_LENGTH;
		printf("%s %i malloc\n", __FILE__, __LINE__);
		*buf = malloc(*size * sizeof(char));
		if (*buf == NULL)
			return (-1);
	}
	index = 0;
	flush_buffer(*buf, *size);
	while (1)
	{
		check_r = read(file_strm, &c, 1);
/*		printf("enter while loop %s %i %i %d\n", __FILE__, __LINE__, check_r, c);*/
		if (check_r == -1)
			return (-1); /*buffer freed elsewhere*/
		if (check_r == 0 && index == 0) /*EOF*/
			return (0);
		if (c != EOF)
		{
/*		printf("getline %i buffer %s\n", __LINE__, *buf);*/
			fill_buffer(buf, size, c, index);
			if (*buf == NULL)
				return (-1);
/*printf("%s %i %lu newly inserted %c\n", __FILE__, __LINE__, index, *(position + index));*/
			++index;
		}
		if (c == '\n')
			break;
	}
	*((*buf) + index - 1) = '\0'; /*room because check is > 0, get rid of new line*/
/*	printf("_getline RETURN %s %i %s %lu\n", __FILE__, __LINE__, *buf, index);*/
	return (index); /*is 1 + to real value as I get rid of new line here*/
}
