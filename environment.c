#include "shell.h"

/*
 * all functions related to the environ global variable
 */
extern char **environ;

/**
 * _getenv - simple version of getenv
 * name: name of variable to find
 * Return: pointer to value of variable or NULL
 */
char *_getenv(const char *name)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		if (check_first(environ[i], name))
		{
			return (environ[i] + _strlen(name) + 1);
		}
		++i;
	}
		return (NULL);
}

/**
 * print_path - prints each directory in PATH one per line
 */
void print_path(void)
{
	int i;
	char *paths;
	char **result;

	paths = _getenv("PATH");
	result = strtow(paths, ':');
	i = 0;
	while (result[i] != NULL)
	{
		printf("%s\n", result[i++]);
	}
	free_strtow(result);
}

/**
 * link_path - create a linked list out of paths in PATH
 * @head: pointer to start of list
 * Return: pointer to linked list, NULL otherwise
 */
node_t *link_path(node_t **head)
{
	int i;
	char **result;
	node_t *check;

	result = strtow(_getenv("PATH"), ':');
	if (result == NULL)
		return (NULL);
	i = 0;
	while (result[i] != NULL)
	{
/*		printf("%s %i, %s\n", __FILE__, __LINE__, result[i]);*/
		check = add_node_end(head, result[i], NULL);
		if (check == NULL)
		{
			free_list(*head);
			return (NULL);
		}
/*		printf("%s %i, %s\n", __FILE__, __LINE__, check->path);*/
		++i;
	}
	free_strtow(result); /*i copied all strings*/
	return (*head);
}


/**
 * _unsetenv - unset variable from environment
 * @name: name of variable
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	int i;
	char **tmp;

/*move on from now, but really should use __findenv*/
	i = 0;
	while (environ[i] != NULL)
	{
		if (check_first(environ[i], name))
		{
			for (tmp = &environ[i];; ++tmp)
				if (!(*tmp = *(tmp + 1)))/*true for NULL*/
					break;
		}
		++i;
	}
	return (0);
}

/**
 * _setenv - simple version of setenv
 * @name: name of variable to add or change
 * @value: value of variable
 * @overwrite: if 0, if name exists no overwrite
 * this function makes copies of the strings pointed to by name and value
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char **tmp;
	char *result, *variable;
	int environ_length, name_length, value_length;

	result = _getenv(name);
	if (result != NULL && !overwrite)
		return (0);
	if (*value == '=')
		value += 1;
/*clean up*/
	_unsetenv(name);
/*find space*/
	tmp = environ;
	while (*tmp != NULL)
		tmp++;
	environ_length = tmp - environ;
/*create variable*/
	name_length = _strlen(name);
	value_length = _strlen(value);
	variable = malloc(name_length + value_length + 2);
	if (variable == NULL)
		return (-1);
	_memcpy(variable, name, name_length);
	variable[name_length] = '=';
	_memcpy(variable + name_length + 1, value, value_length);
	variable[name_length + value_length + 1] = '\0';
/*I am going to start without malloc/realloc the environ variable*/
	environ[environ_length] = variable;
	environ[environ_length + 1] = NULL;
	return (0);
}
