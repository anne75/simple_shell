#include "shell.h"

size_t print_list_t(const node_t *h)
{
	size_t i;
	int j;

	for(i = 0; h != NULL; i++, h = h->next)
	{
		j = _strlen(h->name);
		write(STDOUT_FILENO, h->name, j);
		if (h->value != NULL)
		{
			j = _strlen(h->value);
			write(STDOUT_FILENO, h->value, j);
		}
		write(STDOUT_FILENO, "\n", 1);
	}
	return (i);
}

int main(int argc, char **argv)
{
	node_t *env_start;

	env_start = NULL;
	if (argc != 3)
		return (-1);
	env_link(&env_start);
	_setenv(argv[1], argv[2], 1, &env_start);
	print_list_t(env_start);
	return (0);
}
