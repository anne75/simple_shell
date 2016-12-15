#include "shell.h"

/**
 * link_path - create a linked list out of paths in PATH
 * @head: pointer to start of list
 * @envl: pointer to environ list
 * Return: pointer to linked list, NULL otherwise
 */
node_t *link_path(node_t **head, node_t *envl)
{
	int i;
	char **result;
	node_t *check;

/*PATH exists, no NULL check*/
	result = strtow(_getenv("PATH", envl), ':');
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