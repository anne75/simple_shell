#include "shell2.h"

/**
 * delete_at_index - delete a node at given index
 * @head: beginning of linked list
 * @index: position of node to delete
 * Return: 1 for success, -1 for failure
 */
int delete_at_index(list_t **head, unsigned int index)
{
	list_t *temp, *hold, *hold2;
	unsigned int i;

	i = 0;
	temp = *head;
	if (i == index && index == 0 && temp != NULL)
	{
		hold = temp;
		temp = temp->next;
		free(hold->s);
		free(hold);
		*head = temp;
		return (1);
	}
	else
		index++;
	while (i < index && temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i != index)
		return (-1);
	hold = temp;
	i = 0;
	temp = *head;
	while (i < (index - 2) && temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i != (index - 2))
		return (-1);
	hold2 = temp->next;
	temp->next = hold;
	free(hold2->s);
	free(hold2);
	return (1);
}

/**
 * _unsetenv - unset an environmental variable in the linked list
 * @name: name of the variable to remove
 * @head: beginning of linked list
 * Return: 1 for success, -1 for failure
 */
int _unsetenv(const char *name, list_t **head)
{
	list_t *temp, *hold;
	const char *dup;
	unsigned int i, z;

	temp = *head;
	for (i = 0; name[i] != '\0'; i++)
		;
	dup = malloc(sizeof(char) * (i + 1));
	dup = name;
	i = 0;
	while (temp != NULL)
	{
		if (*name == *temp->s)
		{
			hold = temp;
			z = 0;
			while (*name != '\0' && temp->s[z] != '=' && *name == temp->s[z])
			{
				name++;
				z++;
			}
			if (*name == '\0')
			{
				delete_at_index(head, i);
			}
			else
			{
				temp = hold;
				name = dup;
			}
		}
		i++;
		temp = temp->next;
	}
	return (1);
}
