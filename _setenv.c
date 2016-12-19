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
		printf("REALLOC_M new %s\n", new[i]);
		++i;
	}
	free(a);
	new[i] = val;
	new[i + 1] = NULL;
	printf("%s %i %p\n", __FILE__, __LINE__, new);
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
		printf("%s %i %p\n", __FILE__, __LINE__, new_enva);
		if (new_enva == NULL)
			return (-1);
		printf("_______________________________\n");
		_printenv(new_enva);
		*enva = new_enva;
	}
	return (0);
}




/* /\* int _setenv(const char *name, const char *value, int overwrite, node_t **head) */
/* { */
/* 	char *val; */
/* 	int i, j, k, l; */

/* 	if (!name || !value || !head) */
/* 		return (-1); */
/* 	if (_strchr(name, '=') != NULL) */
/* 		return (-1); */
/* /\\*does not check for = in strings*\\/ */
/* 	val = _getenv(name, *head); */
/* 	if (val != NULL && overwrite) */
/* 		delete_node(head, name); */
/* 	if (val == NULL || overwrite != 0) */
/* 	{ */
/* 		i = _strlen(name); */
/* 		j = _strlen(value); */
/* 		val = malloc(sizeof(char) * (i + j + 2)); */
/* 		if (val == NULL) */
/* 			return (-1); */
/* 		for (l = 0, k = 0; name[k] != '\0'; k++, l++) */
/* 			val[l] = name[k]; */
/* 		val[l++] = '='; */
/* 		for (k = 0; value[k] != '\0'; k++, l++) */
/* 			val[l] = value[k]; */
/* 		val[l] = '\0'; */
/* 		add_node_end(head, val, NULL); */
/* 	} */
/* 	return (0); */
/* } */
