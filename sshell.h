#ifndef _SIMPLE_SHELL_H
#define _SIMPLE_SHELL_H
#define _GNU_SOURCE
/* Header files */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/* Prototypes */
char *g_envi(const char *ev_varia);
char *get_cmmd(char *comm);
char **split_string(char *buff, char *deli);
#endif
