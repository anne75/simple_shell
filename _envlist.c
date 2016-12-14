#include "shell.h"

/**
 * env_link - create a linked list of environmental variables
 * @head: beginning of linked list
 * the helper function copies the string
 * Return: beginning of linked list
 */
node_t *env_link(node_t **head)
{
	extern char **environ;
	int i;
	char *check;

	if (!head)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		check = add_node_end(head, environ[i], NULL);
		if (check == NULL)
		{
			free_list(*head);
			return (NULL);
		}
	}
	return (*head);
}
