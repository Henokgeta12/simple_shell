#include "mi-sh.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
char *mi_concat_strings(char *destz, char *srcz);
char *mi_copy_string(char *destz, char *srcz);
char *mi_get_path(char **environ);
size_t mi_strlen(char *str);
/**
 * mi_update_path - updates the path
 * @args:user input
 * @env: th e environment
 * Return: Str pointer
 */
int mi_update_path(char **args, char **env)
{
	char *token;
	char *command;
	char *path;
	char *path_copy;
	struct stat sb;

	(void)env;

	command = args[0];

	if (strchr(command, '/') != NULL)
		return (0);

	path = getenv("PATH");

	if (path == NULL)
		return (-1);

	path_copy = strdup(path);

	if (path_copy == NULL)
		return (-1);

	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char *pathCmd = (char *)malloc(strlen(token) + strlen(command) + 2);

		if (pathCmd == NULL)
		{
			free(path_copy);
			return (-1);
		}

		sprintf(pathCmd, "%s/%s", token, command);


		if (stat(pathCmd, &sb) == 0 && S_ISREG(sb.st_mode) && (sb.st_mode & S_IXUSR))
		{
			free(path_copy);
			*args = pathCmd;
			return (0);
		}

		free(pathCmd);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (-1);
}
