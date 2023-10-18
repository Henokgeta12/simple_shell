#include "main.h"

/**
 * list_length - determines the length of the list
 * @n: pointer address to the first node
 *
 * Return: the size of the list
 */

size_t list_length(const list_t *n)
{
	size_t a = 0;

	while (n)
	{
		n = n->next;
		a++;
	}
	return (a);
}

/**
 * list_string - returns the array of strings
 * @head: pointer address to the first node
 *
 * Return: an array of strings
 */

char **list_string(list_t *head)
{
	list_t *node = head;
	size_t a = list_length(head), j;
	char **strg;
	char *str;

	if (!head || !a)
		return (NULL);

	strg = malloc(sizeof(char *) * (a + 1));
	if (!strg)
		return (NULL);

	for (a = 0; node; node = node->next, a++)
	{
		str = malloc(_strlen(node->s) + 1);
		if (!str)
		{
			for (j = 0; j < a; j++)
				free(strg[j]);
			free(strg);
			return (NULL);
		}
		str = str_copy(str, node->s);

		strg[a] = str;
	}
	strg[a] = NULL;
	return (strg);
}

/**
 * _printlist - prints the elements of a linked list_t list
 * @n: pointer address to the first node
 *
 * Return: the size of the list
 */

size_t _printlist(const list_t *n)
{
	size_t a = 0;

	while (n)
	{
		_puts(conv_num(n->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(n->s ? n->s : "(nil)");
		_puts("\n");
		n = n->next;
		a++;
	}
	return (a);
}

/**
 * node_start - returns the node that starts with the prefix
 * @node: pointer address to the list head
 * @pref: the string to match
 * @chr: the next character after the prefix
 *
 * Return: the match node or NULL
 */

list_t *node_start(list_t *node, char *pref, char chr)
{
	char *a = NULL;

	while (node)
	{
		a = start_with(node->s, pref);

		if (a && ((chr == -1) || (*a == chr)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_indx - gets the node index
 * @head: pointer address to the list head
 * @node: pointer address to the node
 *
 * Return: the index of the node or -1
 */

ssize_t get_node_indx(list_t *head, list_t *node)
{
	size_t a = 0;

	while (head)
	{
		if (head == node)
			return (a);
		head = head->next;
		a++;
	}
	return (-1);
}
