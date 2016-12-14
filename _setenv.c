#include "shell.h"

/**
 * _setenv - add or change an environmental variable
 * @name: name of the new or exisiting environ var
 * @value: value of the environ var
 * @overwrite: 0 for not overwrite, anything else for overwrite
 * @head: beginning of linked list
 * Return: 1 for success, -1 for fail
 */
int _setenv(const char *name, const char *value, int overwrite, list_t **head)
{
	char *val;
	int i, j, k, l;

	val = _getenv(name, head);
	if (val == NULL || overwrite != 0)
	{
		for (i = 0; name[i] != '\0'; i++)
			;
		for (j = 0; value[j] != '\0'; j++)
			;
		val = malloc(sizeof(char) * (i + j + 2));
		if (val == NULL)
			return (-1);
		for (l = 0, k = 0; name[k] != '\0'; k++, l++)
			val[l] = name[k];
		val[l++] = '=';
		for (k = 0; value[k] != '\0'; k++, l++)
			val[l] = value[k];
		val[l] = '\0';
		add_node_end(head, val);
	}
	if (val != NULL && overwrite == 1)
		return (-1);
	return (1);
}
