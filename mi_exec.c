#include "mi-sh.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
size_t mi_strcomp(char *str1, char *str2);

int mi_exiter(char **args);
int mi_helper(char **args);
int mi_cds(char **args);
int mi_ctrlsD(char **args);

char *mi_builtinCmd[] = {"exit", "help", "cd", "^D"};
int (*builtinCmdArray[])(char **) = {
	&mi_exiter,
	&mi_helper,
	&mi_cds,
	&mi_ctrlsD
};

/**
 * mi_builtinCmd_count - size of builtin
 * Return: size of builtin command
 */
int mi_builtinCmd_count(void)
{
	return (sizeof(mi_builtinCmd) / sizeof(char *));
}
int miFork(char **aS, char **aV, char **env, char *user_in, int numP, int cnt)
{
	pid_t c_process;
	int exit_state = 0;
	int ind = 0;
	char *mi_errorFmt = "%s: %d: %s: not found\n";

	if (aS[0] == NULL)
	{
		return (1);
	}

	for (ind = 0; ind < mi_builtinCmd_count(); ind++)
	{
		if (mi_strcomp(aS[0], mi_builtinCmd[ind]) == 0)
		{
			return (builtinCmdArray[ind](aS));
		}

	}
	c_process = fork();

	if (c_process == 0)
	{
		if (execve(aS[0], aS, env) == -1)
		{
			fprintf(stderr, mi_errorFmt, aV[0], numP, aS[0]);
			if (!cnt)
				free(aS[0]);
			free(aS);
			free(user_in);
			exit(errno);
		}
	}
	else
	{
		wait(&exit_state);
		return (exit_state);
	}

	return (0);
}

/**
 * mi_helper - to show help for my shell
 * @args: list of arguments
 * Return:1 always
 */
int mi_helper(char **args)
{
	int z;

	(void)args;
	for (z = 0; z < mi_builtinCmd_count(); z++)
	{
		printf(" %s\n", mi_builtinCmd[z]);
	}
	return (1);
}
