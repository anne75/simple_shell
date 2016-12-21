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
	free(line);
	if (args == NULL)
	{
		return (0);
	}
	ret_value = bi_function(args, enva, pathl, histl);
	if (ret_value != 101)
	{
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
 * Return: int value
 */
int run_non_bi(char **args, char *function, char **enva)
{
	pid_t childpid;
	int status;

	childpid = fork();
	if (childpid == 0)
	{
		set_to_kill();
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
	}
	free_strtow(args);
	return (0);
}
