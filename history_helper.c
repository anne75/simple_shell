#include "shell.h"

/**
 * delete_first_cmd - delete the first cmd node in linked list
 * essentially 'popping the head off'
 * @file_str: beginning of the history linked list
 * Return: beginning of history linked list
 */
node_t **delete_first_cmd(node_t **file_str)
{
	node_t *temp;

	if (!file_str)
		return (NULL);
	temp = *file_str;
	*file_str = temp->next;
	free(temp->name);
	if (temp->value != NULL)
		free(temp->value);
	free(temp);
	return (file_str);
}

/**
 * _getcmd - get the cmd from the user input
 * @file_strm: file strm, STDIN_FILENO or an opened file
 * Return: string from cmd
 */
char *_getcmd(int file_strm)
{
	ssize_t nline;
	size_t length;
	char *line;

	printf("entered _getcmd\n");
	length = LINE_LENGTH;
	line = malloc(sizeof(char) * length);
	if (line == NULL)
		return (NULL);
	nline = _getline(&line, &length, file_strm);
	if (nline == -1)
	{
		printf("FAIL\n");
		free(line);
		return (NULL);
	}
	line[nline - 1] = '\0';
	printf("le line is %s\n", line);
	return (line);
}

/**
 * history_init - initializes the history list based on .simple_shell_history
 * @file_str: beginning of history linked list
 * Return: beginning of history linked list
 */
node_t **history_init(node_t **file_str)
{
	int fp, nr, i;
	size_t length;
	char *cmd;
	mode_t modes;

	printf("begin initialization\n");
	modes = S_IRUSR | S_IWUSR;
	fp = open(".simple_shell_history", O_RDWR | O_CREAT, modes);
	printf("fp is %d\n", fp);
	if (fp == -1)
		return (NULL);
	printf("successfully opened file\n");
	length = LINE_LENGTH;
	cmd = malloc(sizeof(char) * length);
	do {
		printf("before getline\n");
		nr = _getline(&cmd, &length, fp);
		if (*cmd != '\n' && *cmd != '\0')
		{
			printf("cmd is %s\n", cmd);
			i = _strlen(cmd);
			cmd[i] = '\0';
			add_node_end(file_str, cmd, NULL);
		}
	} while (nr > 0);
	free(cmd);
	if (nr == -1)
	{
		printf("FAIL\n");
		return (NULL);
	}
	/* cmd = _getcmd(fp); */
	/* if (cmd == NULL) */
	/* 	return (file_str); */
	/* else */
	/* { */
	/* 	while (cmd != NULL) */
	/* 	{ */
	/* 		printf("cmd is %s\n", cmd); */
	/* 		add_node_end(file_str, cmd, NULL); */
	/* 		free(cmd); */
	/* 		cmd = _getcmd(fp); */
	/* 	} */
	/* } */
	 printf("LMFAO WHAT\n");
	 close(fp);
	 return (file_str);
}

/**
 * node_count - count and return number of nodes in a list
 * @file_str: beginning of linked list to be counted
 * Return: number of nodes
 */
int node_count(node_t **file_str)
{
	int i;
	node_t *tmp;

	for (i = 0, tmp = *file_str; tmp != NULL; i++, tmp = tmp->next)
	{
		printf("TMP->NAME is %s\n", tmp->name);
	}
	return (i);
}

/**
 * num_to_str - convert a number to a string
 * @i: number to convert
 * Return: a string
 */
char *num_to_str(int i)
{
	int dig;
	int num;
	char *num_str;

	if (i == 0)
	{
		num_str = malloc(sizeof(char) * 2);
		num_str[0] = '0';
		num_str[1] = '\0';
		return num_str;
	}
	for (dig = 1, num = 0; i/dig > 0; dig *= 10, num++)
		;
	num_str = malloc(sizeof(char) * (num + 1));
	if (num_str == NULL)
		return (NULL);
	dig /= 10;
	num = 0;
	while (dig >= 1)
	{
		num_str[num] = (i / dig) + '0';
		i = i % dig;
		dig = dig / 10;
		num++;
	}
	num_str[num] = '\0';
	return (num_str);
}
