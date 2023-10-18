#include "shell.h"
/**
 * handle_builtin - handle an input with paths in global path
 * @file_loc: location of where string or array to add with cmd
 * @built_in: command like ls
 * Return: addition of cmd and strings
 */
char *handle_builtin(char *file_loc, char *built_in)
{
	char *built_in_loc = NULL;
	int i, j = 0;
	int v1, v2;

	if (file_loc == NULL || built_in == NULL)
		return (NULL);
	v1 = size_cmd(file_loc);
	v2 = size_cmd(built_in);
	built_in_loc = malloc(v1 + v2 + 2);
	if (built_in_loc == NULL)
		return (NULL);
	for (i = 0; file_loc[i] != '\0'; i++)
	{
		built_in_loc[i] = file_loc[i];
	}
	if (file_loc[i - 1] != '/')
	{
		built_in_loc[i] = '/';
		i++;
	}
	while (built_in[j] != '\0')
	{
		built_in_loc[i + j] = built_in[j];
		j++;
	}
	built_in_loc[i + j] = '\0';
	return (built_in_loc);
}
