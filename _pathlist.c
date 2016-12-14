#include "shell.h"

/**
 * _strdup - duplicate the string
 * @str: string to duplicate
 * Return: new string that is a duplicate of input
 */
char *_strdup(char *str)
{
	char *dup;
	int i;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		;
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

/**
 * add_node_end - add a node at the end of the linked list
 * @head: beginning of the linked list of type list_t
 * @str: string to put into the ->s of the new node
 * Return: new node
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node, *temp;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->s = _strdup(str);
	free(str);
	new_node->next = NULL;
	temp = *head;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		temp = temp->next;
	}
	return (temp);
}

/**
 * path_link - create a linked list of all the path names in PATH
 * @head: beginning of the linked list
 * @path_str: the path string to parse
 * @max: max number of characters in the path string
 * Return: beginning of linked list
 */
list_t *path_link(list_t **head, char *path_str, int max)
{
	int i, j, k;
	char *str_sec;

	path_str++;
	for (i = 0; path_str[i] != '\0' && i < max; i++)
	{
		for (j = 0; path_str[i + j] != ':' && i + j < max; j++)
			;
		str_sec = malloc(sizeof(char) * (j + 1));
		if (str_sec == NULL)
			return (NULL);
		for (k = 0; k < j; k++)
		{
			str_sec[k] = path_str[i + k];
		}
		str_sec[k] = '\0';
		add_node_end(head, str_sec);
		i += j;
	}
	return (*head);
}

/**
 * print_list_t - print a linked list of type list_t
 * @h: beginning of the list_t type linked list
 * Return: number of nodes printed
 */
size_t print_list_t(const list_t *h)
{
	size_t i;
	for (i = 0; h != NULL; i++, h = h->next)
		printf("%s\n", h->s);
	return (i);
}
