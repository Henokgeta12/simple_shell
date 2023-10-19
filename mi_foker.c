#include "mi-sh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
size_t mi_strcomp(char *str1, char *str2);

int mi_exiter(char **args);
int mi_helper(char **args);
int mi_cds(char **args);
int mi_ctrlsD(char **args);

/**
 * mi_exiter - to exit
 * @args:arguments list
 * Return: 1 on success otehrwise 0
 */
int mi_exiter(char **args)
{
	(void)args;
	free(args);
	return (200);
}

/**
 * mi_cds - to change directory to another
 * @args: list or arguments
 * Return: 1 on success otherwise 0
 */
int mi_cds(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * mi_ctrlsD - takes care of cntrl+D
 * @args: list of arguments
 * Return:0 always
 */
int mi_ctrlsD(char **args)
{
	(void)args;
	free(args);
	return (200);
}
