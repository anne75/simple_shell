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
	printf("val is %s\n", val);
	printf("i is %d\n", i);
	new[i] = _strdup(val);
	printf("%s\n", val);
	new[i + 1] = NULL;
	free(a);
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
	val = _getenv(name, *enva);
	if (val != NULL && overwrite)
		_unsetenv(name, *enva);
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
		free(val);
		printf("%s %i %p\n", __FILE__, __LINE__, (void *)new_enva);
		if (new_enva == NULL)
			return (-1);

/*		_printenv(new_enva);*/
		*enva = new_enva;
/*		_printenv(*enva);*/
	}
	return (0);
}

/**
 * _setenv_help - helper function due to built-in struct
 * @args: argument array
 * @enva: environment array
 * @pathl: path linked list
 * @histl: history linked list
 * Return: 0 for success
 */
int _setenv_help(char **args, char ***enva, node_t **pathl, node_t **histl)
{
	(void) pathl;
	(void) histl;
	_setenv(args[1], args[2], 1, enva);
	return (0);
}
