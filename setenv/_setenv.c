#include "shell.h"

/**
 * _setenv - add or change an environmental variable
 * @name: name of the new or exisiting environ var
 * @value: value of the environ var
 * @overwrite: 0 for not overwrite, anything else for overwrite
 * @head: beginning of environment linked list
 * Return: 1 for success, -1 for fail
 */
int _setenv(char *name, char *value, int overwrite, node_t **head)
{
	char *val;
	int i, j, k, l;

	if (!name || !value || !head)
		return (-1);
	if (_strchr(name, '=') != NULL)
		return (-1);
/*does not check for = in strings*/
	val = _getenv(name);
	if (val != NULL && overwrite)
		delete_node(head, name);
	if (val == NULL || overwrite != 0)
	{
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
		add_node_end(head, val, NULL);
	}
	return (0);
}
