#ifndef _MAIN_H_
#define _MAIN_H_

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

/* read and write buffers */

#define BUFFER_SIZE 1024
#define WRITE_BUFF_SIZE 1024
#define BUFF_FLUSH -1

/* command chaining */

#define COMMAND_NORM 0
#define COMMAND_OR 1
#define COMMAND_AND 2
#define COMMAND_CHAIN 3

/* convert_number */

#define CONV_LOWER 1
#define CONV_UNSIGNED 2

/* using system getline */

#define USE_GETLINE 0
#define USE_STRTOK 0

#define HISTORY_FILE ".simple_shell_history"
#define HISTORY_MAXIMUM 4096

extern char **environ;

/**
 * struct list_str - singly linked list
 * @num: the number as an integer
 * @s: string in the list
 * @next: pointer to the next node
 */

typedef struct list_str
{
	int num;
	char *s;
	struct list_str *next;
} list_t;

/**
 * struct pass_info - contains the pseudo-arguments to pass into a function
 * @arg: a string from getline containing arguments
 * @argv: an array of strings from arg
 * @path: the string path of the current command
 * @argc: argument count
 * @l_count: the error line count
 * @er_num: the error code for exit()
 * @lcount_flag: if on, count this line of input
 * @fl_name: the program filename
 * @env: local copy of the environ
 * @environ: custom modified copy of the environ
 * @hist: history node
 * @alias: alias node
 * @env_change: it's on if the environ was changed
 * @stat: return status of the last executed command
 * @command_buff: address of pointer to the command_buff, on if chaining
 * @command_buff_type: COMMAND_type ||, &&, ;
 * @read_fd: file descriptor form which to read line input
 * @histcount: the history line number count
 */

typedef struct pass_info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int l_count;
	int er_num;
	int lcount_flag;
	char *fl_name;
	list_t *env;
	list_t *hist;
	list_t *alias;
	char **environ;
	int env_change;
	int stat;
	char **command_buff;
	int command_buff_type;
	int read_fd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
                0, 0, 0}

/**
 * struct builtin - contains a builtin string and functions
 * @type: builtin command flag
 * @function: function
 */

typedef struct builtin
{
	char *type;
	int (*function)(info_t *);
} builtin_table;

/* shell-loop */

int shell(info_t *, char **);
int fnd_builtin(info_t *);
void fnd_command(info_t *);
void fork_command(info_t *);

/* parser */

int _command(info_t *, char *);
char *dupl_char(char *, int, int);
char *_path(info_t *, char *, char *);

/* loop */

int loop_shell(char **);

/* err */

void _eputs(char *);
int _eputchar(char);
int _putfd(char k, int fd);
int _putsfd(char *s, int fd);

/* string */

int _strlen(char *);
int _strcmp(char *, char *);
char *start_with(const char *, const char *);
char *_strcat(char *, char *);

/* string1 */

char *str_copy(char *, char *);
char *str_dupl(const char *);
void _puts(char *);
int _putchar(char);

/* exits */

char *strn_cpy(char *, char *, int);
char *strn_cat(char *, char *, int);
char *str_char(char *, char);

/* token */

char **token(char *, char *);
char **tokenizer(char *, char*);

/* realloc */

char *set_mem(char *, char, unsigned int);
void _free(char *);
void *my_realloc(void *, unsigned int, unsigned int);

/* memory */

int pfree(void **);

/* atoi */

int interact(info_t *);
int _delimeter(char, char *);
int _alpha(int);
int _atoi(char *);

/* err1 */

int _erratoi(char *);
void print_err(info_t *, char *);
int print_dec(int, int);
char *conv_num(long int, int, int);
void rm_comment(char *);

/* built */

int my_exit(info_t *);
int my_cd(info_t *);
int my_help(info_t *);

/* built1 */

int _myhist(info_t *);
int _alias(info_t *);

/* g_line */

ssize_t _getinput(info_t *);
int my_getline(info_t *, char **, size_t *);
void sigintHandler(int);
ssize_t inp_buffer(info_t *info, char **buff, size_t *len);
ssize_t read_buffer(info_t *info, char *buf, size_t *i);

/* info */

void _clearinfo(info_t *);
void _setinfo(info_t *, char **);
void _freeinfo(info_t *, int);

/* envi */

char *get_env(info_t *, const char *);
int my_env(info_t *);
int my_setenv(info_t *);
int my_unsetenv(info_t *);
int env_list(info_t *);

/* gtenv */

char **_getenviron(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* history */

char *hist_file(info_t *info);
int _writehist(info_t *info);
int _readhist(info_t *info);
int build_histlist(info_t *info, char *buff, int lcount);
int renum_hist(info_t *info);

/* linked_list */

list_t *_addnode(list_t **, const char *, int);
list_t *add_end(list_t **, const char *, int);
size_t print_liststr(const list_t *);
int delete_node_indx(list_t **, unsigned int);
void _freelist(list_t **);

/* linked_list1 */

size_t list_length(const list_t *);
char **list_string(list_t *);
size_t _printlist(const list_t *);
list_t *node_start(list_t *, char *, char);
ssize_t get_node_indx(list_t *, list_t *);

/* variables */

int _chain(info_t *, char *, size_t *, size_t);
void confirm_chain(info_t *, char *, size_t *, size_t, size_t);
int rep_alias(info_t *);
int rep_variable(info_t *);
int rep_str(char **, char *);

#endif

