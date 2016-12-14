#include "shell2.h"

/**
 * env_link - create a linked list of environmental variables
 * @head: beginning of linked list
 * Return: beginning of linked list
 */
list_t *env_link(list_t **head)
{
	extern char **environ;
	int i;
	char *var_str;

	for (i = 0; environ[i] != NULL; i++)
	{
		var_str = _strdup(environ[i]);
		add_node_end(head, var_str);
	}
	return (*head);
}
