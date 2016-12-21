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
	printf("enter %s %i\n", __FILE__, __LINE__);
	printf("%s\n", _getenv("PATH", enva));
	result = strtow(_getenv("PATH", enva), ":");
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
/*		printf("%s %i, %s\n", __FILE__, __LINE__, check->name);*/
		++i;
	}
	free_strtow(result); /*i copied all strings*/
	return (*head);
}
