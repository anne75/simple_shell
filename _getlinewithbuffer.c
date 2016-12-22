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

	if (!buffer)
		return (-1);
	*buffer = malloc(sizeof(char) * 1); /*I need to malloc the buffer whatever*/
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

	buffer = NULL;
	if (!line || !remainder)
		return (-1);
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
		check_line = _strtok_r(line, NULL, ";\n\0", remainder);
	}
	if (*remainder == NULL) /*just reached end of buffer, and buffer malloc'ed*/
	{
		printf("freeing buffer\n");
		free(buffer);
	}
	if (check_line == NULL)
		return (-1);
	return (_strlen(check_line) + 1); /*differentiate from CtrlD*/
}
