#include "shell.h"

/**
 * env_array - create an array of environmental variables
 *
 *
 * Return: beginning of linked list
 */
char **env_array(void)
{
	int i;
	char **array;

	for (i = 0; environ[i]; ++i)
		;

	array = malloc(sizeof(char *) * (i + 1));
	if (array == NULL)
		return (NULL);

	printf("%s %i\n", __FILE__, __LINE__);
	for (i = 0; environ[i]; ++i)
	{
		array[i] = _strdup(environ[i]);
		if (array[i] == NULL)
		{
			while (--i >= 0)
				free(array[i]);
			free(array);
			return (NULL);
		}
	}
	array[i] = NULL;
	printf("return %s %i\n", __FILE__, __LINE__);
	return (array);
}
