#include "shell.h"

/**
 * _resize_list - resize a linked list
 * @file_str: beginning of linked list to resize
 * Return: resized list
 */
node_t **_resize_list(node_t **file_str)
{
	int total_len, extra_len, i;
	node_t *tmp;

	if (file_str == NULL || *file_str == NULL)
		return (file_str);
	tmp = *file_str;
	printf("beginning value is %s\n", tmp->name);
	printf("begin resize_list\n");
	total_len = node_count(file_str);
	printf("total_len is %d\n", total_len);
	if (total_len <= 4096)
		return (file_str);
	printf("shouldnt' have gotten here\n");
	extra_len = total_len - 4096;
	for (i = 0; i < extra_len; i++)
	{
		file_str = delete_first_cmd(file_str);
	}
	return (file_str);
}

/**
 * _printhist - print out the history linked list
 * @histl: beginning of linked list
 * @file_strm: file output stream
 * @i: beginning node print count
 * Return: nothing, void function
 */
void _printhist(node_t *histl, int file_strm, int i)
{
	char *index;

	printf("int i is %d\n", i);
	printf("enter _printhist\n");
	printf("int file_strm is %d\n", file_strm);
	while (histl != NULL)
	{
		if (file_strm == STDOUT_FILENO)
		{
			index = num_to_str(i);
			if (index == NULL)
				return;
			write(file_strm, " ", 1);
			write(file_strm, index, _strlen(index));
			write(file_strm, "  ", 2);
			free(index);
		}
		if (*histl->name != '\n' && *histl->name != 0)
			write(file_strm, histl->name, _strlen(histl->name));
		write(file_strm, "\n", 1);
		histl = histl->next;
		i++;
	}
}

/**
 * _history_out - output the history linked list
 * @file_str: linked list
 * @file_strm: output stream
 * Return: file_str
 */
node_t **_history_out(node_t **file_str, int file_strm)
{
	int total_len, print_start, i;
	node_t *temp;

	if (file_str == NULL)
		return (file_str);
	printf("histroy_out start\n");
	print_start = 0;
	printf("going to call _resize_list(file_str)\n");
	file_str = _resize_list(file_str);
	printf("successfully resize_list,\n");
	total_len = node_count(file_str);
	printf("node count is %d\n", total_len);
	if (total_len > 1000)
		print_start = total_len - 1000;
	temp = *file_str;
	for (i = 0; i < print_start; i++, temp = temp->next)
		;
	printf("i is %d\n", i);
	printf("begin print function\n");
	_printhist(temp, file_strm, print_start);
	return (file_str);
}

/**
 * _history_write - write out history linked list to file
 * @file_str: beginning of list
 * Return: file_str beginning
 */
node_t **_history_write(node_t **file_str)
{
	int fd;
	mode_t permish;

	permish = S_IRUSR | S_IWUSR;
	printf("begin write\n");
	fd = open(".simple_shell_history", O_RDWR | O_CREAT | O_TRUNC, permish);
	printf("file open, stream is %d\n", fd);
	if (fd == -1)
		return (NULL);
	file_str = _history_out(file_str, fd);
	return (file_str);
}
