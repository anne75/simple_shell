#include "shell.h"

/**
 * _unsetenv - unset an environmental variable in the linked list
 * @name: name of the variable to remove
 * @head: beginning of linked list
 * Return: 1 for success, -1 for failure
 */
int _unsetenv(const char *name, node_t **head)
{
	node_t *temp;

	if (!name || !head)
		return (-1);

	temp =*head;
	while (temp != NULL)
	{
		if (check_first(temp->name, name))
		{
			delete_node(head, name);
			return (0);
		}
		temp = temp->next;
	}
	return (0);
}
