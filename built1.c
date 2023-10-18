#include "main.h"

/**
 * my_hist - returns history of the shell
 * @info: arguments
 * Return: 0  Always (Success)
 */
int my_hist(info_t *info)
{
	_printlist(info->hist);
	return (0);
}
/**
 * unset_alias - changed alias to defult
 * @info: parameter
 * @str: string
 * Return: 0 (Success) else 1
 */
int unset_alias(info_t *info, char *str)
{
	char *k, t;
	int ret;

	k = strchr(str, '=');
	if (!k)
		return (1);
	t = *k;
	*k = 0;
	ret = delete_node_indx(&(info->alias), get_node_indx(info->alias,
				node_start(info->alias, str, -1)));
	*k = t;
	return (ret);
}
/**
 * set_alias - changes alias to a new string
 * @info: parameter
 * @str: string
 * Return: 1 Success else 0 failed
 */
int set_alias(info_t *info, char *str)
{
	char *k;

	k = strchr(str, '=');
	if (!k)
		return (0);
	if (!*k++)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - displays alias
 * @node: node
 * Return: 0 else 1 error
 */
int print_alias(list_t *node)
{
	char *k = NULL, *t = NULL;

	if (node)
	{
		k = strchr(node->s, '=');
		for (t = node->s; t <= k; t++)
		{
			_putchar(*t);
			_putchar('\\');
			_puts(k + 1);
			_puts("\n");
			return (0);
		}
	}
	return (1);
}
/**
* my_alias - merrors the alias
* @node: node
* Return: 0 else 1 if error
*/
int my_alias(info_t *info)
{
	int k = 0;
	char *t = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (k = 1; info->argv[k]; k++)
	{
		t = str_char(info->argv[k], '=');
		if (t)
			set_alias(info, info->argv[k]);
		else
			print_alias(node_start(info->alias, info->argv[k], '='));
	}
	return (0);
}
