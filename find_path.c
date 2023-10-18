#include "main.h"

/**
 * find_path - Find the full path to an executable in PATH.
 * @command: The command to find in PATH.
 * Return: Full path to the executable or NULL if not found.
 */
char *find_path(char *command)
{
	char *path, *path_copy, *full_path, *path_token;
	int command_len, token_len;
	struct stat buf;

	path = getenv("PATH");

	if (command && path)
	{
		path_copy = strdup(path);
		command_len = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			token_len = strlen(path_token);
			full_path = malloc(command_len + token_len + 2);
			strcpy(full_path, path_token);
			strcat(full_path, "/");
			strcat(full_path, command);
			strcat(full_path, "\0");
			if (stat(full_path, &buf) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			else
			{
				free(full_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buf) == 0)
			return (command);
		return (NULL);
	}
	else 
	{
		perror("no command input");
		return (NULL);
	}
	return (NULL);

}
