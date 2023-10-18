
#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<stdbool.h>
#include<stdarg.h>
#include<sys/stat.h>
/* prototypes */

int execmd(char **argv);
extern char **environ;
char *find_path(char *command);
int strings_equal(const char *str1, const char *str2);
int str_length(const char *str);
void my_exit(char *input);
void print_env(void);
bool is_empty(const char *str);

/**
 * static char buffer[BUFFER_SIZE];
 * static size_t buffer_pos;
 * static size_t buffer_size;
 * ssize_t own_getline(char **lineptr, size_t *n, FILE *stream);
 */

#endif
