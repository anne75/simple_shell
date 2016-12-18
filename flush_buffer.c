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
