#include "shell.h"

/**
 * read_it_all - reads a lot at a time
 * @buffer: the resulting buffer
 * @fd: a file descriptor
 * @end_of_file: EOF flag
 * Return: number of characters read, -1 on error
 */
ssize_t read_it_all(char **buffer, int fd, int *end_of_file)
{
	int nr, count;
	char buf_help[BUF_LENGTH];

	if (!buffer)
		return (-1);
	*buffer = malloc(sizeof(char) * 1);
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
	if (nr == 0)
		*end_of_file = 1;
	if (nr == -1)
		return (-1);
	return (count);
}




/**
 * _getlinewithbuffer - return one line from a buffer that may have more
 * @buffer: buffer to store values
 * @line: where to put the result, it should be NULL, needed to pass it around
 * @rem: where to look for a line
 * @fd: file descriptor
 * @end_of_file: end of file flag, do not reprompt
 * Return: number of characters read, -1 on error
 */
ssize_t _getlinewithbuffer(char **buffer, char **line,
			   char **rem, int fd, int *end_of_file)
{
	char *check_line;
	ssize_t check;

	if (!line || !rem)
		return (-1);
	if (*rem == NULL)
	{
		printf("%s %i\n", __FILE__, fd);
		if (fd == STDIN_FILENO)
			write(STDOUT_FILENO, "$ ", 2);
		check = read_it_all(buffer, fd, end_of_file);
		if (check <= 0)
		{
			if (*buffer != NULL)
				free(*buffer);
			return (check);
		}
		check_line = _strtok_r(line, *buffer, ";\n\0", rem);
	}
	else
	{
		check_line = _strtok_r(line, NULL, ";\n\0", rem);
	}
	if (*rem == NULL) /*just reached end of buffer, and buffer malloc'ed*/
	{
		free(*buffer);
	}
	if (check_line == NULL)
	{
		free(*buffer);
		return (-1);
	}
	return (_strlen(check_line) + 1); /*differentiate from CtrlD*/
}
