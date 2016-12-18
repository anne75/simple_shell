#include "shell.h"

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
	char *help1, *help2; /*cant operate on pointer to void*/

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (ptr);
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
	free(ptr);
	return (new);
}
