#include "main.h"

/**
 * my_exit - leaved or terminates the shell
 * @info: has arguments
 *
 * Return: exit with coments
 */

int my_exit(info_t *info)
{
	int exitstat;

	if (info->argv[1])
	{
		exitstat = _erratoi(info->argv[1]);
		if (exitstat == -1)
		{
			info->stat = 2;
			print_err(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->er_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->er_num = -1;
	return (-2);
}

/**
 * my_cd - changes the directory from previous directory
 * @info: arguments
 * Return: 0 Success (Always)
 */

int my_cd(info_t *info)
{
	char *t, *dir, buffer[1024];
	int cdir_ret;

	t = getcwd(buffer, 1024);
	if (!t)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = get_env(info, "HOME=");
		if (!dir)
			cdir_ret = chdir((dir = get_env(info, "PWD=")) ? dir : "/");
		else
			cdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!get_env(info, "OLDPWD="))
		{
			_puts(t);
			_putchar('\n');
			return (1);
		}
		_puts(get_env(info, "OLDPWD=")), _putchar('\n');
		cdir_ret = chdir((dir = get_env(info, "OLDPWD=")) ? dir : "/");
	}
	else
		cdir_ret = chdir(info->argv[1]);
	if (cdir_ret == -1)
	{
		print_err(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", get_env(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 * my_help - returns help info
 * @info: argument
 * Return: 0 Always (Success)
 */

int my_help(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
