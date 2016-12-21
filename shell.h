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

/**
 * struct bi_s - struct for built in commands
 * @name: name of command
 * @help: helper string
 * @fp: function to pointer
 */
typedef struct bi_s
{
	char *name;
	char *help;
	int (*fp)(char **args, char ***enva, node_t **pathl, node_t **histl);
} bi_t;

/*extern variable*/
extern char **environ;

/*in bi_function.c*/
int bi_function(char **args, char ***enva, node_t **pathl, node_t **histl);

/*in _cd.c*/
int _cd(char **args, char ***envl, node_t **pathl, node_t **histl);

/*in command_path.c*/
char *what_path(char *name, node_t *pathl);

/*in _ctrl_c.c*/
void sig_kill(int sig);
void set_to_kill(void);
void sig_catch(int sig);
void set_to_catch(void);

ssize_t _getline(char **, size_t *, int);

/*in env_array.c*/
char **env_array(void);

/*in execute_command.c*/
int execute_command(char *line, char ***enva, node_t **pathl, node_t **histl);
int run_non_bi(char **args, char *function, char **enva);

/*in _exit_.c*/
int _exit_(char **args, char ***enva, node_t **pathl, node_t **histl);

/*in flush_buffer.c*/
void flush_buffer(char *buffer, size_t size);

/*in free_enva.c*/
int free_enva(char **enva);

/*in _getenv.c*/
int bi_getenv(char **args, char ***enva, node_t **pathl, node_t **histl);
char *_getenv(const char *name, char **enva);

/*in _getlinewhithbuffer.c*/
ssize_t read_it_all(char **buffer, int fd);
ssize_t _getlinewithbuffer(char **line, char **remainder, int fd);

/*in _help.c*/
int _help(char **args, char ***enva, node_t **pathl, node_t **histl);
int _help_all(bi_t *array);

/*in helper_list.c*/
node_t *add_node_end(node_t **head, const char *, const char *);
void free_list(node_t *head);
int delete_node(node_t **head, const char *name);
int change_node_value(node_t *head, char *name, char *value);

/* in helper_string.c*/
int _strlen(const char *);
int check_first(char *, const char*);
char *_strdup(const char *str);
char *_memcpy(char *dest, const char *src, unsigned int n);
const char *_strchr(const char *s, char c);

/*in helper_string2.c*/
int _strcmp(char *s1, char *s2);
char *strchr_r(char *s, char c);
int _atoi(char *s);

/*in _history.c*/
int _history(char **args, char ***enva, node_t **pathl, node_t **histl);

/*in history.c*/
node_t **_resize_list(node_t **file_str);
void _printhist(node_t *histl, int file_strm, int i);
node_t **_history_out(node_t **file_str, int file_strm);
node_t **_history_write(node_t **file_str);

/*in history_helper*/
node_t **delete_first_cmd(node_t **file_str);
char *_getcmd(int file_strm);
node_t **history_init(node_t **file_str);
int node_count(node_t **file_str);
char *num_to_str(int i);

/*in initialize_shell*/
int initialize_shell(char ***enva, node_t **pathl, node_t **histl, char **);

/*in link_path*/
node_t *link_path(node_t **head, char **envl);

/*in nobufgetline.c*/
void fill_buffer(char **buf, size_t *size, char c, size_t index);
ssize_t _getline(char **buf, size_t *size, int file_strm);

/*in _printenv*/
int _printenv(char **args, char ***enva, node_t **pathl, node_t **histl);

/*in prompt*/
char *prompt(char **remainder, char **enva, node_t *pathl, node_t *histl);

/*in _realloc*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*in remove_comments*/
char *remove_comments(char *line);

/*in _setenv*/
char **realloc_matrix(char **a, char *val);
int _setenv(const char *name, const char *value, int overwrite, char ***enva);
int _setenv_help(char **args, char ***enva, node_t **pathl, node_t **histl);

/*in _strconcat*/
char *_strnconcat(char *s1, char *s2, int n);

/*in _strspn*/
int _strspn(char *s, char *delimeter);
int _strcspn(char *s, char *delimeter);

/*in strtow*/
int getnbw(unsigned char *str, int ascii[]);
int _strw(unsigned char *s, int ascii[]);
char *_getw(unsigned char *s, char *dest, int l);
char **strtow(char *str, char *delimeters);
void free_strtow(char **s);

/*int _strtok_r.c*/
char *_strtok_r(char **result, char *line, char *delim, char **remain);

/*in _unsetenv*/
/*int _unsetenv(const char *name, node_t **head);*/
int _unsetenv(const char *name, char **enva);
int _unsetenv_help(char **args, char ***enva, node_t **pathl, node_t **histl);

#endif
