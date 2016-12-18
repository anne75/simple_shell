#include "shell.h"

/**
 * _unsetenv - unset variable from environment
 * @name: name of variable
 * @enva: array of environ
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name, char **enva)
{
	int i;
	char **tmp;


	i = 0;
	while (enva[i] != NULL)
	{
		if (check_first(enva[i], name))
		{
			free(enva[i]);
			for (tmp = &enva[i];; ++tmp)
				if (!(*tmp = *(tmp + 1)))/*true for NULL*/
					break;
		}
		++i;
	}
	return (0);
}


/* int _unsetenv(const char *name, node_t **head) */
/* { */
/* 	node_t *temp; */

/* 	if (!name || !head) */
/* 		return (-1); */

/* 	temp =*head; */
/* 	while (temp != NULL) */
/* 	{ */
/* 		if (check_first(temp->name, name)) */
/* 		{ */
/* 			delete_node(head, name); */
/* 			return (0); */
/* 		} */
/* 		temp = temp->next; */
/* 	} */
/* 	return (0); */
/* } */
