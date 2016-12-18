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
	*buffer = NULL;
	count = 0;
	flush_buffer(buf_help, BUF_LENGTH); /*need to initialize - valgrind*/
	do {
		nr = read(fd, buf_help, BUF_LENGTH - 1);
		buf_help[nr + 1] = '\0';
		*buffer= _strconcat(*buffer, buf_help);
		count += nr;
	} while (nr > 0);

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

	buffer = NULL;
	if (*remainder == NULL)
	{
		if ((check = read_it_all(&buffer, fd)) <= 0)
		{
			free(buffer);
			return (check);
		}
	}
	check_line = _strtok_r(line, buffer, ";\n\0", remainder);
	if (check_line == NULL)
		return (-1);
	return (_strlen(check_line));
}


/* int main(int ac, char **av) */
/* { */
/* 	char *line, *remainder; */
/* 	ssize_t nr; */
/* 	int fd, i; */
/* 	(void) ac; */

/* 	line = NULL; */
/* 	remainder = NULL; */

/* 	fd = open(av[1], O_RDONLY); */
/* 	if (fd == -1) */
/* 		return (0); */
/* 	i = 0; */
/* 	while ((nr = _getlinewithbuffer(&line, &remainder, fd)) > 0) */
/* 	{ */
/* 		printf("TURN %i ---%s---\n", i++, line); */
/* 		free(line); */
/* 	} */
/* 	close(fd); */
/* 	return (0); */
/* } */
