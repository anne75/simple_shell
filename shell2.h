#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * struct make_list - singly linked list of strings
 * @s: string value
 * @next: pointer to next node
 *
 * Description: struct for path linked list and
 * environ variable linked lists
 */
typedef struct make_list
{
	char *s;
	struct make_list *next;
} list_t;

ssize_t _getline(char **lineptr, size_t *n);
char *_strdup(char *str);
list_t *add_node_end(list_t **head, char *str);
list_t *path_link(list_t **head, char *path_str, int max);
list_t *env_link(list_t **head);
int _setenv(const char *name, const char *value, int overwrite, list_t **head);
int _unsetenv(const char *name, list_t **head);
int delete_at_index(list_t **head, unsigned int index);
size_t print_list_t(const list_t *h);
int num_words(char *temp_val);
char **_strtok(char *str);
int _strlen(char *str);
char *_getenv(const char *name, list_t **head);
#endif
