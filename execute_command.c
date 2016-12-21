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
	int ret_value;
	char **args, *function;
	char *error_message = ": command not found\n";

	args = NULL;

	args = strtow(line, " \t\v\r\f");
/*			printf("%s %i free\n", __FILE__, __LINE__);*/
	printf("%s %i ===============%pfree\n", __FILE__, __LINE__, (void *) line);
	free(line);
	if (args == NULL)
	{
		printf("execute_command: empty line\n");
		return (0);
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
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, error_message, _strlen(error_message));
		free_strtow(args);
		return (0);
	}
	return (run_non_bi(args, function, *enva));
}

/**
 * run_non_bi - run a non built-in command
 * @args: arguments for function
 * @function: function name
 * @enva: pointer to environment array
 */
int run_non_bi(char **args, char *function, char **enva)
{
	pid_t childpid;
	int status;

	childpid = fork();
	if (childpid == 0)
	{
		set_to_kill();
/*		printf("simple shell: in child process\n");*/
		if (execve(function, (char *const *) args, enva) == -1)
		{
			perror("simple shell");
			free_strtow(args);
			free(function);
			_exit(1);
			return (-1);
		}
	}
	else
	{
		waitpid(childpid, &status, 0);
		free(function);
		printf("in parent: child process is %u status is %i current pid is %u\n", childpid, status, getpid());
	}
	printf("FREE ARGSxs");
	free_strtow(args);
	printf("%s %i\n", __FILE__, __LINE__);
	return (0);
}
