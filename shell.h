#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <signal.h>

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

/*extern variable*/
extern char **environ;

/*in bi_function*/
int bi_function(char **args, node_t **envl);

/*in _cd*/
int _cd(char *s, node_t *envl);

ssize_t _getline(char **, size_t *, int);

/*in command_path*/
char *what_path(char *name, node_t *pathl);

/*in exit*/
int _exit_(char *s);

/*in _getenv*/
char *_getenv(const char *name, node_t *head);

/*in _help*/
int _help(char *s);

/* in helper_string*/
int _strlen(const char *);
int check_first(char *, const char*);
char *_strdup(const char *str);
char *_memcpy(char *dest, const char *src, unsigned int n);
const char *_strchr(const char *s, char c);

/*in helper_strin2*/
int _strcmp(char *s1, char *s2);

/*in helper_list*/
node_t *add_node_end(node_t **head, const char *, const char *);
void free_list(node_t *head);
int delete_node(node_t **head, const char*name);

/*in _history.c*/
int _history(void);

/*in linkenv*/
node_t *env_link(node_t **head);

/*in link_path*/
node_t *link_path(node_t **head, node_t *envl);

/*in _printenv*/
void _printenv(node_t *envl);

/*in _setenv*/
int _setenv(const char *name, const char *value, int overwrite, node_t **head);

/*in strtow*/
char **strtow(char *str, char delimeter);
void free_strtow(char **s);

/*in _unsetenv*/
int _unsetenv(const char *name, node_t **head);

/*in prompt*/
char *prompt(void);

/*in nobufgetline*/
void flush_buffer(char *buffer, size_t size);
void fill_buffer(char **buf, size_t *size, char c, size_t index);

/*in _ctrl_c*/
void sig_kill(int sig);
void set_to_kill(void);
void sig_catch(int sig);
void set_to_catch(void);

#endif
