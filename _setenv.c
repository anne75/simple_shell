#include "shell.h"

/**
 * realloc_matrix - reallocate the matrix for env
 * @a: pointer to array, terminates with NULL
 * @val: string to add
 * This function is only for here, no generic at all
 * Return: pointer to new array
 */
char **realloc_matrix(char **a, char *val)
{
	char **new;
	int i;

	if (!a)
		return (NULL);

	for (i = 0; a[i]; ++i)
		;
	new = malloc(sizeof(char *) * (i + 2));
	if (new == NULL)
		return (NULL);

	i = 0;
	printf("%s %i\n", __FILE__, __LINE__);
	while (a[i])
	{
		new[i] = a[i];
/*		printf("REALLOC_M new %s\n", new[i]);*/
		++i;
	}
	new[i] = val;
	new[i + 1] = NULL;
	free_strtow(a);
	printf("%s %i %p\n", __FILE__, __LINE__, (void *)new);
	return (new);
}


/**
 * _setenv - add or change an environmental variable
 * @name: name of the new or exisiting environ var
 * @value: value of the environ var
 * @overwrite: 0 for not overwrite, anything else for overwrite
 * @enva: pointer to environ array
 * Return: 1 for success, -1 for fail
 */
int _setenv(const char *name, const char *value, int overwrite, char ***enva)
{
	char *val;
	int i, j, k, l;
	char **new_enva;

	if (!name || !value || !enva)
		return (-1);
	if (_strchr(name, '=') != NULL)
	return (-1);
/*does not check for = in strings*/
	printf("in setenv\n");
	printf("name is %s\n", name);
	printf("value is %s\n", value);
	printf("overwrite is %d\n", overwrite);
	val = _getenv(name, *enva);
	printf("string from _getenv is %s\n", val);
	if (val != NULL && overwrite)
	{
		printf("unsetting env val\n");
		_unsetenv(name, *enva);
	}
	printf("_unsetenv success\n");
	if (val == NULL || overwrite != 0)
	{
/*create new string*/
		i = _strlen(name);
		j = _strlen(value);
		val = malloc(sizeof(char) * (i + j + 2));
		if (val == NULL)
			return (-1);
		for (l = 0, k = 0; name[k] != '\0'; k++, l++)
			val[l] = name[k];
		val[l++] = '=';
		for (k = 0; value[k] != '\0'; k++, l++)
			val[l] = value[k];
		val[l] = '\0';
		printf("%s %i new string %s\n", __FILE__, __LINE__, val);
/*realloc environ, need triple pointer*/
		new_enva = realloc_matrix(*enva, val);
/*		free(val);*/
		printf("%s %i %p\n", __FILE__, __LINE__, (void *)new_enva);
		if (new_enva == NULL)
			return (-1);

/*		_printenv(new_enva);*/
		enva = &new_enva;
/*		_printenv(*enva);*/
	}
	return (0);
}
