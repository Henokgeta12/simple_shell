#ifdef MY_SH_H
#define MY_SH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **my_environ;
char *mi_builtinCmd[] = {"exit", "help", "cd", "^D"};
int (*builtinCmdArray[]) (char **) = {&mi_exiter, &mi_helper, &mi_cds, &mi_ctrlsD};
int mi_exiter(char **args);
int mi_helper(char **args);
int mi_cd(char **args);
int mi_ctrlsD(char **args);

size_t mi_strcomp(char *str1, char *str2);
size_t mi_strncomp(char *str1, char *str2, size_t no);
int mi_putcharz(char charz);
size_t mi_strlen(char *str);
char *mi_concat_strings(char *destz, char *srcz);
char *mi_copy_string(char *destz, char *srcz);

char *mi_get_input(void);
char **mi_tokenize(char *user_in);
int miFork(char **args, char **aV, char **env, char *user_in, int numP, int cnt);
void mi_executes(char **args, char *user_in, int should_exit);
void mi_display_environ(char **environ);
char mi_get_path(char **environ);
int mi_update_path(char **args, char **env);

#endif
