#include "shell.h"

/**
 * _strlen - find the length of a string
 * @str: string to find length of
 * Return: i, length
 */
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _getenv - get environmental variable
 * @name: name of the variable
 * @head: beginning of env var linked list
 * Return: string starting with '='
 */
char *_getenv(const char *name, list_t **head)
{
	char *string;
	list_t *temp, *hold;

	temp = *head;
	while (temp != NULL)
	{
		if (*name == *temp->s)
		{
			hold = temp;
			while (*name != '\0' && *temp->s != '=' && *name == *temp->s)
			{
				name++;
				temp->s++;
			}
			if (*name == '\0')
			{
				string = _strdup(hold->s);
			}
		}
		temp = temp->next;
	}
	return (string);
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
