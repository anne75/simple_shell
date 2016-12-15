#include <unistd.h>
#include <stdlib.h>
#include "shell.h"


/**
 *flush_buffer - cleanup
 *@buffer: a buffer
 *@size: size of buffer
 */
void flush_buffer(char *buffer, size_t size)
{
	size_t i;

	for (i = 0; i < size; ++i)
		buffer[i] = '\0';
}

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: size in bytes allocated for ptr
 * @new_size: new size in bytes
 * The contents will be unchanged in the range from the start of the
 * region up  to the minimum of the old and new sizes.  If the new size
 * is larger than the old size, the added memory will not be initialized
 *. If ptr is NULL, then the call is  equivalent  to malloc(size), for
 * all  values of size; if size is equal to zero, and ptr is not NULL,
 * then the call is equivalent to free(ptr).
 * Return: pointer to new memory space, or NULL if fails
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int min, i;
	void *new;
	char *help1, *help2;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
	printf("%s %i malloc\n", __FILE__, __LINE__);
	new = malloc(new_size);
	if (new == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new);

	min = (old_size > new_size) ? new_size : old_size;
	i = 0;
	help1 = ptr;
	help2 = new;

	while (i < min)
	{
		*(help2 + i) = *(help1 + i);
		++i;
	}
	printf("%s %i free\n", __FILE__, __LINE__);
	free(ptr);
	return (new);
}


/**
 * fill_buffer
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
	if (index >= *size -1) /*I need 2 free spots at this point*/
	{
		printf("realloc buffer\n");
		*buf = _realloc(*buf, *size, *size * 2);
		if (*buf == NULL)
			return;
		*size = *size * 2;
		printf("after realloc %lu, \n", *size);
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
 * Return: number of characters read on success, -1 otherwise
 */
ssize_t _getline(char **buf, size_t *size)
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
		check_r = read( STDIN_FILENO, &c, 1);
/*		printf("enter while loop %s %i %i %d\n", __FILE__, __LINE__, check_r, c);*/
		if(check_r == -1)
			return (-1); /*buffer freed elsewhere*/
		if (check_r == 0) /*EOF or C^C*/
			return (-1) ;
		if(c == EOF)
		{
			printf("getline EOF index %lu\n", index);
			if (index == 0)
				return (-1);
			break;
		}

/*		printf("getline %i buffer %s\n", __LINE__, *buf);*/
		fill_buffer(buf, size, c, index);
		if (*buf == NULL)
			return (-1);
/*		printf("%s %i %lu newly inserted %c \n", __FILE__, __LINE__, index, *(position + index));*/
		++index;
		if (c == '\n')
			break;
	}
	*((*buf) + index) = '\0'; /*room because check*/
	printf("_getline RETURN %s %i %s %lu\n", __FILE__, __LINE__, *buf, index);
	return (index);
}
