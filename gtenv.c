#include "main.h"

/**
 * _getenviron - retrives the environ
 * @info: arguments
 * Return: 0 (Success)
 */

char **_getenviron(info_t *info)
{
	if (!info->environ || info->env_change)
	{
		info->environ = list_string(info->env);
		info->env_change = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - deletes enviromental variables
 * @vari: string
 * @info: arguments
 * Return: 1 if success else 0
 */

int _unsetenv(info_t *info, char *vari)
{
	list_t *node = info->env;
	size_t t = 0;
	char *r;

	if (!node || !vari)
		return (0);

	while (node)
	{
		r = start_with(node->s, vari);
		if (r && *r == '=')
		{
			info->env_change = delete_node_indx(&(info->env), t);
			t = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		t++;
	}
	return (info->env_change);
}

/**
 * _setenv - starts an environment
 * @info: arguments
 * @value: string env
 * @vari: string ptoperty
 * Return: Always 0 (Success)
 */

int _setenv(info_t *info, char *vari, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *l;

	if (!vari || !value)
		return (0);

	buff = malloc(_strlen(vari) + _strlen(value) + 2);
	if (!buff)
		return (1);
	strcpy(buff, vari);
	strcat(buff, "=");
	strcat(buff, value);
	node = info->env;
	while (node)
	{
		l = start_with(node->s, vari);
		if (l && *l == '=')
		{
			free(node->s);
			node->s = buff;
			info->env_change = 1;
			return (0);
		}
		node = node->next;
	}
	add_end(&(info->env), buff, 0);
	free(buff);
	info->env_change = 1;
	return (0);
}
