#include "shell.h"

/**
 * env_link - create a linked list of environmental variables
 * @head: beginning of linked list
 * the helper function copies the string
 * Return: beginning of linked list
 */
node_t *env_link(node_t **head)
{
	int i;
	node_t *check;

	if (!head)
		return (NULL);
	printf("%s %i\n", __FILE__, __LINE__);
	for (i = 0; environ[i] != NULL; i++)
	{
		check = add_node_end(head, environ[i], NULL);
		printf("%s %i\n", __FILE__, __LINE__);
		if (check == NULL)
		{
			free_list(*head);
			return (NULL);
		}
	}
	return (*head);
}
