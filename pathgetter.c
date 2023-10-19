#include "mi-sh.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
size_t mi_strncomp(char *str1, char *str2, size_t no);

/**
 *mi_get_path - gets path evironment value
 *@environ: the environment variables to get value from
 *Return: value of the nvironment path
 */
char *mi_get_path(char **environ)
{
	size_t ind = 0;
	size_t cnt = 6;
	size_t starting_comp = 0;
	char *cmd_path = NULL;

	for (ind = 0; mi_strncomp(environ[ind], "PATH= ", 6); ind++)
	{
		if (strncmp(environ[ind], "PATH=", cnt) == 0)
			break;
	}
	if (environ[ind] == NULL)
		return (NULL);
	while (environ[ind][starting_comp])
	{
		starting_comp++;
		cnt++;
	}

	cmd_path = (char *)malloc(sizeof(char) * (cnt + 1));

	if (cmd_path == NULL)
		return (NULL);

	starting_comp = 5;
	cnt = 0;
	while (environ[ind][starting_comp])
	{
		cmd_path[cnt] = environ[ind][starting_comp];
		starting_comp++;
		cnt++;
	}

	cmd_path[cnt] = '\0';
	return (cmd_path);
}
