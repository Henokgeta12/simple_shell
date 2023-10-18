#include "main.h"

/**
 * _command - checks if a command is an executable file
 * @info: info_t struct containing info
 * @path: path of the file to the command
 *
 * Return: 1 if true, 0 otherwise
 */

int _command(info_t *info, char *path)
{
	struct stat st;
	(void)info;

	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dupl_char - duplicates the characters of the string
 * @path_str: the PATH string containing string to duplicate
 * @start: the index at the beginning of the substring
 * @stop: the index at the end of the substring
 *
 * Return: pointer to the new buffer containing duplicated string
 */

char *dupl_char(char *path_str, int start, int stop)
{
	static char buffer[1024];
	int a = 0, c = 0;

	for (c = 0, a = start; a < stop; a++)
		if (path_str[a] != ':')
			buffer[c++] = path_str[a];
	buffer[c] = 0;

	return (buffer);
}

/**
 * _path - locates the command in the PATH string
 * @info: the info_t struct containing info
 * @path_str: the PATH string to search for the command
 * @command: the command to find in the PATH
 *
 * Return: the full path of command if found, otherwise NULL
 */

char *_path(info_t *info, char *path_str, char *command)
{
	int a = 0, pos = 0;
	char *path;

	if (!path_str)
		return (NULL);

	if ((_strlen(command) > 2) && start_with(command, "./"))
	{
		if (_command(info, command))
			return (command);
	}
	while (1)
	{
		if (!path_str[a] || path_str[a] == ':')
		{
			path = dupl_char(path_str, pos, a);

			if (!*path)
				_strcat(path, command);
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}
			if (_command(info, path))
				return (path);
			if (!path_str[a])
				break;
			pos = a;
		}
		a++;
	}
	return (NULL);
}
