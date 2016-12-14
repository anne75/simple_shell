#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#define BUF_LENGTH 64
#define LINE_LENGTH 20
/*#define EOF (-1)*/

/* structs */

/**
 * node_s - generic node for all lists
 * @name: a string containing the  name
 * @value: value, executable or NULL
 * @next: pointer to next node
 */
typedef struct node_s
{
	char *name;
	char *value;
	struct node_s *next;
} node_t;


ssize_t _getline(char **, size_t *);

/* in helper_string*/
int _strlen(const char *);
int check_first(char *, const char*);
char *_strdup(const char *str);
char *_memcpy(char *dest, const char *src, unsigned int n);
char *_strchr(char *s, char c);

/*in helper_list*/
node_t *add_node_end(node_t **head, const char *, const char *);
void free_list(node_t *head);

/*in environment*/
char *_getenv(const char *name);
void print_path(void);
node_t *link_path(node_t **head);
int _setenv(const char *name, const char *value, int overwrite);
int _setenv(const char *name, const char *value, int overwrite);

/*in strtow*/
char **strtow(char *str, char delimeter);
void free_strtow(char **s);

/*in prompt*/
char *prompt(void);

/*in getfunction*/
char *which(char *name);

#endif
