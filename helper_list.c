#include "shell.h"

/*this files contains helper functions for linked lists*/

/**
 * free_list - free a linked list
 * @head: linked list
 *
 */
void free_list(node_t *head)
{
	node_t *tmp;

	if (head == NULL)
		return;

	tmp = head;
	while (head != NULL)
	{
		free(head->name);
		if (head->value != NULL)
			free(head->value);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_node_end - add a node at the end of a list
 * @head: pointer to the first element of a list
 * @name: value of the node to insert
 * @value: second value to insert, or NULL
 * Return: address of new element or NULL if failed
 */
node_t *add_node_end(node_t **head, const char *name, const char *value)
{
	node_t *new;
	node_t **tmp;

	if(!head || !name)
		return (NULL);

	new = malloc(sizeof(node_t));
	if (new == NULL)
		return (NULL);

	new->name = _strdup(name);
	if (new->name == NULL)
	{
		free(new);
		return (NULL);
	}
	if (value == NULL)
	{
		new->value = NULL;
	}
	else
	{
		new->value = _strdup(value);
		if (new->value == NULL)
		{
			free(new);
			free(new->name);
			return (NULL);
		}
	}
	new->next = NULL;
/*try to apply Linus Torvald's good taste, no if*/
	tmp = head;
	while (*tmp != NULL)
		tmp = &((*tmp)->next);
	*tmp = new;
	return (new);
}

/**
 * delete_node - delete a node in a list
 * @head: pointer to linked list
 * @name: name in the node
 * Return: 1 on success, -1 on failure
 */
int delete_node(node_t **head, char *name)
{
	node_t **tmp;
	node_t *tmpnode;

	if (!head || !name)
		return (-1);

	tmp = head;
	while (*tmp != NULL && (*tmp)->name != name)
		tmp = &((*tmp)->next);
	if (*tmp)
	{
		tmpnode = *tmp;
		free(tmpnode->name);
		if (tmpnode->value != NULL)
			free(tmpnode->value);
		*tmp = tmpnode->next;
		free(tmpnode);
		return (1);
	}
	return (-1);
}

/**
 * change_node_value - change the value for a particular name
 * @name: name of node
 * @value: new value
 * Return: 1 on success, -1 on failure
 */
int change_node_value(node_t *head, char *name, char *value)
{
	if (!head || !name || !value)
		return (-1);

	while (head != NULL)
	{
		if (head->name == name)
		{
			if (head->value != NULL)
				free(head->value);
			head->value = _strdup(value);
			if (head->value == NULL)
				return (-1);
			return (1);
		}
		head = head->next;
	}
	return (-1);
}
