#include "main.h"

/**
 * _chain - test if the current char in a buffer is a chain delimeter
 * @info: the parameter struct
 * @buffer: the character buffer
 * @p: address of the current position in the buffer
 * @n: parameter
 * Return: 1 0n success, 0 otherwise
 */

int _chain(info_t *info, char *buffer, size_t *p, size_t n)
{
	n = *p;

	if (buffer[n] == '|' && buffer[n + 1] == '|')
	{
		buffer[n] = 0;
		n++;
		info->command_buff_type = COMMAND_OR;
	}
	else if (buffer[n] == '&' && buffer[n + 1] == '&')
	{
		buffer[n] = 0;
		n++;
		info->command_buff_type = COMMAND_AND;
	}
	else if (buffer[n] == ';')
	{
		buffer[n] = 0;
		info->command_buff_type = COMMAND_CHAIN;
	}
	else
		return (0);
	*p = n;
	return (1);
}

/**
 * confirm_chain - confirms the chain based on the last status
 * @info: parameter struct
 * @buffer: the character buffer
 * @pos: the current position in the buffer
 * @idx: the start positon in the buffer
 * @leng: the length of the buffer
 *
 */

void confirm_chain(info_t *info, char *buffer, size_t *pos,
		size_t idx, size_t leng)
{
	size_t k = *pos;

	if (info->command_buff_type == COMMAND_AND)
	{
		if (info->stat)
		{
			buffer[idx] = 0;
			k = leng;
		}
	}
	if (info->command_buff_type == COMMAND_OR)
	{
		if (!info->stat)
		{
			buffer[idx] = 0;
			k = leng;
		}
	}
	*pos = k;
}

/**
 * rep_alias - replace an alias in the string
 * @info: parameter struct
 *
 * Return: 1 if its replaced, 0 otherwise
 */

int rep_alias(info_t *info)
{
	int n;
	list_t *node;
	char *m;

	for (n = 0; n < 10; n++)
	{
		node = node_start(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);

		m = str_char(node->s, '=');

		if (!m)
			return (0);

		m = str_dupl(m + 1);

		if (!m)
			return (0);
		info->argv[0] = m;
	}
	return (1);
}

/**
 * rep_variable - replaces the variables in the string
 * @info: parameter string
 *
 * Return: 1 if it's replaced, 0 if not
 */

int rep_variable(info_t *info)
{
	int k = 0;
	list_t *node;

	for (k = 0; info->argv[k]; k++)
	{
		if (info->argv[k][0] != '$' || !info->argv[k][1])
			continue;
		if (!_strcmp(info->argv[k], "$?"))
		{
			rep_str(&(info->argv[k]), str_dupl(conv_num(info->stat, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[k], "$$"))
		{
			rep_str(&(info->argv[k]), str_dupl(conv_num(getpid(), 10, 0)));
			continue;
		}

		node = node_start(info->env, &info->argv[k][1], '=');
		if (node)
		{
			rep_str(&(info->argv[k]), str_dupl(str_char(node->s, '=') + 1));
			continue;
		}
		rep_str(&info->argv[k], str_dupl(""));
	}
	return (0);
}

/**
 * rep_str - replace a string
 * @old_str: address of the old string
 * @new_str: the new string
 *
 * Return: 1 on success, 0 otherwise
 */

int rep_str(char **old_str, char *new_str)
{
	free(*old_str);
	*old_str = new_str;
	return (1);
}
