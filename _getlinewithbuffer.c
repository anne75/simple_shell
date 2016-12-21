#include "shell.h"

/**
 * read_it_all - reads a lot at a time
 * @buffer: the resulting buffer
 * @fd: a file descriptor
 * Return: number of characters read, -1 on error
 */
ssize_t read_it_all(char **buffer, int fd)
{
	int nr, count;
	char buf_help[BUF_LENGTH];

	printf("%s %i READ it all\n", __FILE__, __LINE__);
	if (!buffer)
		return (-1);
	*buffer = malloc(sizeof(char) * 1); /*I need to malloc the buffer whatever*/
/*	printf("malloc buffer getlinewithbuffer\n");*/
	if (*buffer == NULL)
		return (-1);
	(*buffer)[0] = '\0';
	count = 0;
	flush_buffer(buf_help, BUF_LENGTH); /*need to initialize - valgrind*/
	while ((nr = read(fd, buf_help, BUF_LENGTH - 1)) > 0)
	{
		buf_help[nr + 1] = '\0';
		*buffer = _strnconcat(*buffer, buf_help, nr);
		count += nr;
/*		printf("%s last value in buffer is %d isatty is %d\n",__FILE__, buf_help[nr] == '\0', isatty(fd)); */
		if (isatty(fd) && buf_help[nr] == '\0')
		{
			break;
		}
	}

	if (nr == -1)
		return (-1);
	return (count);
}




/**
 * _getlinewithbuffer - return one line from a buffer that may have more
 * @line: where to put the result, it should be NULL, needed to pass it around
 * @remainder: where to look for a line
 * @fd: file descriptor
 * Return: number of characters read, -1 on error
 */
ssize_t _getlinewithbuffer(char **line, char **remainder, int fd)
{
	char *buffer, *check_line;
	ssize_t check;

	if (!line || !remainder)
		return (-1);
/*	printf("%s %i before loop is there remainder\n", __FILE__, __LINE__);*/
	if (*remainder == NULL)
	{
		check = read_it_all(&buffer, fd);
		if (check <= 0)
		{
			free(buffer);
			return (check);
		}
		check_line = _strtok_r(line, buffer, ";\n\0", remainder);
	}
	else
	{
/*		printf("%s remainder before _strtok is %s\n", __FILE__, *remainder);*/
		check_line = _strtok_r(line, NULL, ";\n\0", remainder);
	}
	if (*remainder == NULL) /*just reached end of buffer, and buffer malloc'ed*/
	{
		printf("FREE free buffer getline%p\n", (void *) buffer);
		free(buffer);
	}
/*	printf("%s remainder return _strtok is %s\n", __FILE__, *remainder);*/
	if (check_line == NULL)
		return (-1);
	return (_strlen(check_line) + 1); /*differentiate from CtrlD*/
}
