#include "main.h"

/**
 * _clearinfo - clears infomation
 * @info: address
 * Return: none
 */

void _clearinfo(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * _setinfo - sets info
 * @info: address
 * @av: argument
 * Return: none
 */

void _setinfo(info_t *info, char **av)
{
	int n = 0;

	info->fl_name = av[0];
	if (info->arg)
	{
		char *token = strtok(info->arg, "\t");
		if (token) 
		{
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = str_dupl(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (n = 0; info->argv && info->argv[n]; n++)
			;
		info->argc = n;

		rep_alias(info);
		rep_variable(info);
		}
	}
}

/**
 * _freeinfo - releases info
 * @info: address
 * @all: frees everthing selected
 * Return: none
 */

void _freeinfo(info_t *info, int all)
{
	pfree((void **)&info->argv);
	info->argv = NULL;
	info->path = NULL;

	if (all)
	{
		if (!info->command_buff)
			free(info->arg);
		if (info->env)
			_freelist(&(info->env));
		if (info->hist)
			_freelist(&(info->hist));
		if (info->alias)
			_freelist(&(info->alias));
		pfree((void **)&info->environ);
		info->environ = NULL;
		pfree((void **)info->command_buff);
		if (info->read_fd > 2)
			close(info->read_fd);
		_putchar(BUFF_FLUSH);
	}
}
