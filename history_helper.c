#include "shell.h"

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

ssize_t _get_line_cmd(char **buf, size_t *size, int file_strm)
{
	size_t index;
	char c;
	int check_r;

	if (!buf || !size)
		return (-1);
	if (!*buf)
	{
		*size = BUF_LENGTH;
		printf("%s %i malloc\n", __FILE__, __LINE__);
		*buf = malloc(*size * sizeof(char));
		if (*buf == NULL)
			return (-1);
	}

	index = 0;
	flush_buffer(*buf, *size);
	while (1)
	{
		check_r = read(file_strm, &c, 1);
		if (check_r == -1)
			return (-1);
		if (check_r == 0)
			return (-1);
		if (c == EOF)
		{
			printf("getline EOF index %lu\n", index);
			if (index == 0)
				return (-1);
			break;
		}

		fill_buffer(buf, size, c, index);
		if (*buf == NULL)
			return (-1);

		++index;
		if (c == '\n')
			break;
	}
	*((*buf) + index) = '\0';
	printf("_getcmd RETURN %s %i %s %lu\n", __FILE__, __LINE__, *buf, index);
	return (index);
}

char *_getcmd(int file_strm)
{
	ssize_t nline;
	size_t length;
	char *line;

	length = LINE_LENGTH;
	line = malloc(sizeof(char) * length);
	if (line == NULL)
		return (NULL);
	nline = _get_line_cmd(&line, &length, file_strm);
	if (nline == -1)
	{
		free(line);
		exit(1);
		return (NULL);
	}
	line[nline - 1] = '\0';
	return (line);
}
node_t **history_init(node_t **file_str)
{
	int fp;
	char *cmd;

	fp = open(".simple_shell_history", O_RDONLY | O_CREAT, 0600);
	if (fp == -1)
		return (NULL);
	while ((cmd = _getcmd(fp)) != NULL)
	{
		add_node_end(file_str, cmd, NULL);
	}
	close(fp);
	return (file_str);
}
