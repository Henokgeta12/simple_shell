#include "mi-sh.h"
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <stddef.h>
#include <errno.h>
int miFork(char **aS, char **aV, char **env, char *user_in, int numP, int cnt);
int mi_update_path(char **args, char **env);
void mi_display_environ(char **environ);
char **mi_tokenize(char *user_in);
char *mi_get_input(void);
size_t mi_strcomp(char *str1, char *str2);
/**
 * main - entry point of my program
 * @ac:no of args ie argument count
 * @av:array of args ie argument vector
 * @environ:enviromnent
 * Return: 1 on success otherwise 0
 */

int main(int ac, char **av, char **environ)
{
	char **cmd_arg = NULL;
	int cmdCnt = 0, exit_state = 0, isCmdinP = 0;
	char *userLine = NULL;

	(void)ac;
	while (1)
	{
		errno = 0;
		userLine = mi_get_input();
		if (userLine == NULL && errno == 0)
			return (0);
		if (userLine)
		{
			cmdCnt++;
			cmd_arg = mi_tokenize(userLine);
			if (!cmd_arg)
				free(userLine);
			if (!mi_strcomp(cmd_arg[0], "env"))
				mi_display_environ(environ);
			else
			{
				isCmdinP = mi_update_path(cmd_arg, environ);
				exit_state = miFork(cmd_arg, av, environ, userLine, cmdCnt, isCmdinP);
				if (exit_state == 200)
				{
					free(userLine);
					return (0);
				}
				if (isCmdinP == 0 && cmd_arg[0] != NULL)
					free(cmd_arg[0]);
			}
			free(cmd_arg);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exit_state);
		}
		free(userLine);
	}
	return (exit_state);
}
