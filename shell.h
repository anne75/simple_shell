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
 * struct node_s - generic node for all lists
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


/**
 * struct shell_s - struct to contain info about the shell
 * @enva: pointer to environment
 * @pathl: pointer to path list
 * @histl: pointer to history list
 * @args: pointer to arguments
 * @remainder: pointer to remainder in non interactive mode
 */
typedef struct shell_s
{
	char **enva;
	node_t *pathl;
	node_t *histl;
	char **args;
	char *remainder;
} shell_t;


/*extern variable*/
extern char **environ;

/*in bi_function*/
int bi_function(char **args, char ***enva, node_t **pathl, node_t **histl);

/*in _cd*/
int _cd(char **args, char **envl);

ssize_t _getline(char **, size_t *, int);

/*in command_path*/
char *what_path(char *name, node_t *pathl);

/*in env_array*/
char **env_array(void);

/*in exit*/
int _exit_(char **enva, node_t **pathl, node_t **histl, char **args);

/*in execute_command*/
int execute_command(char *line, char ***enva, node_t **pathl, node_t **histl);
int run_non_bi(char **args, char *function, char **enva);

/*in free_enva*/
int free_enva(char **enva);

/*in flush_buffer*/
void flush_buffer(char *buffer, size_t size);

/*in _getenv*/
/*char *_getenv(const char *name, node_t *head);*/
char *_getenv(const char *name, char **enva);
int bi_getenv(const char *name, char **enva);

/*in _getlinewhithbuffer*/
ssize_t _getlinewithbuffer(char **line, char **remainder, int fd);

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
int delete_node(node_t **head, const char *name);

/*in _history.c*/
int _history(node_t **histl);

/*in initialize_shell*/
int initialize_shell(char ***enva, node_t **pathl, node_t **histl, char **);

/*in linkenv*/
/*node_t *env_link(node_t **head);*/

/*in link_path*/
node_t *link_path(node_t **head, char **envl);

/*in _printenv*/
void _printenv(char **enva);

/*in prompt*/
char *prompt(char **remainder, char **enva, node_t *pathl, node_t *histl);

/*in _realloc*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*in remove_comments*/
char *remove_comments(char *line);

/*in _setenv*/
char **realloc_matrix(char **a, char *val);

int _setenv(const char *name, const char *value, int overwrite, char ***enva);


/*in _strconcat*/
char *_strnconcat(char *s1, char *s2, int n);

/*in _strspn*/
int _strspn(char *s, char *delimeter);
int _strcspn(char *s, char *delimeter);

/*in strtow*/
char **strtow(char *str, char *delimeters);
void free_strtow(char **s);

/*int _strtok*/
char *_strtok_r(char **result, char *line, char *delim, char **remain);

/*in _unsetenv*/
/*int _unsetenv(const char *name, node_t **head);*/
int _unsetenv(const char *name, char **enva);

/*in nobufgetline*/
void flush_buffer(char *buffer, size_t size);
void fill_buffer(char **buf, size_t *size, char c, size_t index);

/*in _ctrl_c*/
void sig_kill(int sig);
void set_to_kill(void);
void sig_catch(int sig);
void set_to_catch(void);

/*in history_helper*/
node_t **delete_first_cmd(node_t **file_str);
char *_getcmd(int file_strm);
node_t **history_init(node_t **file_str);
int node_count(node_t **file_str);
char *num_to_str(int i);

/*in history*/
node_t **_resize_list(node_t **file_str);
void _printhist(node_t *histl, int file_strm, int i);
node_t **_history_out(node_t **file_str, int file_strm);
node_t **_history_write(node_t **file_str);

#endif
