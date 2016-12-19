#include "shell.h"

/**
 * execute_command - execute command entered by user
 * @line: the line as entered
 * @enva: pointer to environ array
 * @pathl: linked list of path variable
 * @histl: linked list for history
 * Return: no idea
 */
int execute_command(char *line, char ***enva, node_t **pathl, node_t **histl)
{
	int ret_value, status;
	char **args, *function;
	pid_t childpid;

	args = NULL;
	args = strtow(line, ' ');
/*			printf("%s %i free\n", __FILE__, __LINE__);*/
	free(line);
	if (args == NULL)
	{
		printf("simple shell: strtow ran into error\n");
		exit(98);
	}
	ret_value = bi_function(args, enva, pathl, histl);
	if (ret_value != 101)
	{
		printf("EXecuted built in\n");
		free_strtow(args);
		return (ret_value);
	}
	function = what_path(args[0], *pathl);
	if (function == NULL)
	{
		free_strtow(args);
		return (0);
	}
	childpid = fork();
	if (childpid == 0)
	{
		set_to_kill();
		printf("simple shell: in child process\n");
		if (execve(function, (char *const *) args, *enva) == -1)
		{
			perror("Child Error:");
			return (-1);
		}
	}
	else
	{
		waitpid(childpid, &status, 0);
		free(function);
		printf("in parent: child process is %u status is %i current pid is %u\n", childpid, status, getpid());
	}
	printf("FREE ARGS\n");
	free_strtow(args);
	printf("%s %i\n", __FILE__, __LINE__);
	return (0);
}
