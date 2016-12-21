#include "shell.h"

/**
 * link_path - create a linked list out of paths in PATH
 * @head: pointer to start of list
 * @enva: pointer to environ list
 * Return: pointer to linked list, NULL otherwise
 */
node_t *link_path(node_t **head, char **enva)
{
	int i;
	char **result;
	node_t *check;

/*PATH exists, no NULL check*/
	result = strtow(_getenv("PATH", enva), ":");
	if (result == NULL)
		return (NULL);
	i = 0;
	while (result[i] != NULL)
	{
		check = add_node_end(head, result[i], NULL);
		if (check == NULL)
		{
			free_list(*head);
			return (NULL);
		}
		++i;
	}
	free_strtow(result); /*i copied all strings*/
	return (*head);
}
