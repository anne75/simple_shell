#include "shell.h"

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
 * print_list_t - print a linked list of type list_t
 * @h: beginning of the list_t type linked list
 * Return: number of nodes printed
 */
size_t print_list_t(const node_t *h)
{
	size_t i;
	for (i = 0; h != NULL; i++, h = h->next)
		printf("%s\n", h->s);
	return (i);
}
