#include "shell.h"

/**
 * _getenv - get environmental variable
 * @name: name of the variable
 * @head: beginning of env var linked list
 * Return: string starting with '='
 */
char *_getenv(const char *name, node_t *head)
{
	if (!name)
		return (NULL);
	if (_strchr(name, '=')!= NULL)
		return (NULL);

	while (head != NULL)
	{
		if (check_first(head->name, name))
		{
			return (head->name + _strlen(name) + 1);
		}
		head = head->next;
	}
	return (NULL);
}


/*
int main(void)
{
	char *lol;
	list_t *head;

	head = NULL;
	env_link(&head);
	lol = malloc(sizeof(char) * 1024);
	lol = _getenv("PATH", &head);
	printf("%s\n", lol);
	return (0);
}
*/
