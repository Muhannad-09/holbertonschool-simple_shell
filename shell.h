#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* --- Structs --- */

/**
 * struct liststr - singly linked list for env/history/alias
 * @num: numeric ID
 * @str: string data
 * @next: pointer to next node
 */

typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - carries shell state
 */

typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;

/* Initializer for passinfo */
#define INFO_INIT \
	{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, 0, 0, 0}

/**
 * struct builtin - mapping between built-in name and function
 * @type: the command string
 * @func: the function to execute
 */

typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* hsh.c */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);

/* Shell state management */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* Input and execution */
ssize_t get_input(info_t *);
char **get_environ(info_t *);
char *_getenv(info_t *, const char *);
char *find_path(info_t *, char *, char *);
int is_cmd(info_t *, char *);
int _strcmp(char *, char *);
int interactive(info_t *);
int is_delim(char, char *);
void print_error(info_t *, char *);
int _putchar(char);
void _puts(char *);
int _eputchar(char);
void _eputs(char *);
int write_history(info_t *);

/* builtin_emulators.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* builtin_emulators2.c */
int _myhistory(info_t *);
int _myalias(info_t *);

/* env.c */
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);

#endif /* SHELL_H */

