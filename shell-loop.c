#include "main.h"

/**
 * shell - the main loop for the shell program
 * @info: the parameter and return info struct
 * @av: argument vector
 *
 * Return: 0 on success, 1 on error or error code
 */

int shell(info_t *info, char **av)
{
	ssize_t ret = 0;
	int builtin_ret = 0;

	while (ret != -1 && builtin_ret != -2)
	{
		_clearinfo(info);
		if (interact(info))
			_puts("$~ ");
		_eputchar(BUFF_FLUSH);
		ret = _getinput(info);

		if (ret != -1)
		{
			_setinfo(info, av);
			builtin_ret = fnd_builtin(info);

			if (builtin_ret == -1)
				fnd_command(info);
		}
		else if (interact(info))
			_putchar('\n');
		_freeinfo(info, 0);
	}
	_writehist(info);
	_freeinfo(info, 1);

	if (!interact(info) && info->stat)
		exit(info->stat);

	if (builtin_ret == -2)
	{
		if (info->er_num == -1)
			exit(info->stat);
		exit(info->er_num);
	}
	return (builtin_ret);
}

/**
 * fnd_builtin - finds a built-in command
 * @info: the parameter and return info struct
 *
 * Return: -1 if not found, 0 on success, 1 on failure, 2 if exits
 */

int fnd_builtin(info_t *info)
{
	int a, builtin_ret = -1;

	builtin_table builtintbl[] = {
		{"exit", my_exit},
		{"env", my_env},
		{"help", my_help},
		{"history", _myhist},
		{"setenv", my_setenv},
		{"unsetenv", my_unsetenv},
		{"cd", my_cd},
		{"alias", _alias},
		{NULL, NULL}
	};

	for (a = 0; builtintbl[a].type; a++)
	{
		if (_strcmp(info->argv[0], builtintbl[a].type) == 0)
		{
			info->l_count++;
			builtin_ret = builtintbl[a].function(info);
			break;
		}
	}
	return (builtin_ret);
}

/**
 * fnd_command - finds a command in PATH
 * @info: the parameter and return info struct
 */

void fnd_command(info_t *info)
{
	char *path = NULL;
	int a, m;

	info->path = info->argv[0];

	if (info->lcount_flag == 1)
	{
		info->l_count++;
		info->lcount_flag = 0;
	}
	for (a = 0, m = 0; info->arg[a]; a++)
		if (!_delimeter(info->arg[a], "\t\n"))
			m++;
	if (!m)
		return;

	path = _path(info, get_env(info, "PATH="), info->argv[0]);

	if (path)
	{
		info->path = path;
		fork_command(info);
	}
	else
	{
		if ((interact(info) || get_env(info, "PATH=") ||
					info->argv[0][0] == '/') &&
				_command(info, info->argv[0]))
			fork_command(info);
		else if (*(info->arg) != '\n')
		{
			info->stat = 127;
			print_err(info, "not found\n");
		}
	}
}

/**
 * fork_command - forks an execution thread to run a command
 * @info: the parameter and return info struct
 */

void fork_command(info_t *info)
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		perror("Error:");
		return;
	}
	if (pid == 0)
	{
		if (execve(info->path, info->argv, _getenviron(info)) == -1)
		{
			_freeinfo(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->stat));
		if (WIFEXITED(info->stat))
		{
			info->stat = WEXITSTATUS(info->stat);
			if (info->stat == 126)
				print_err(info, "Permission denied\n");
		}
	}
}
