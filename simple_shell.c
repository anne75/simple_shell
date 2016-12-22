#include "shell.h"


/**
 * main - get a line containing a command, parses it and executes
 *
 * Return: always 0
 */
int main(void)
{
	char *line;
/*	int i;*/
	node_t *pathl;
	char **enva;
	int check;
	node_t *histl;
	char *remainder;
	char *buffer;
	int e_o_f;

	histl = NULL;
	buffer = NULL;
	e_o_f = 0;
	check =	initialize_shell(&enva, &pathl, &histl, &remainder);
	if (check == -1)
		return (0);
	while (1)
	{
		set_to_catch();
		line = prompt(&buffer, &remainder, enva, pathl, histl, &e_o_f);
		if (line != NULL)
/*line is NULL if nothing or only comments, EOF caught before*/
		{
/*		printf("simple shell: The line is %s\n", line);*/
			add_node_end(&histl, line, NULL);
			execute_command(line, &enva, &pathl, &histl);
		}
		if (e_o_f && remainder == NULL)
			break;
	}
	_history_write(&histl);
	free_enva(enva);
	free_list(pathl);
	free_list(histl);
	return (0);
}
