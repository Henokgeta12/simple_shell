#include "main.h"

/**
 * _addnode - adds node to the start of the linked list
 * @head: address of head node
 * @s: string of the node
 * @num: node index
 *
 * Return: size of the list
 */

list_t *_addnode(list_t **head, const char *s, int num)
{
	list_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	set_mem((void *)new, 0, sizeof(list_t));
	new->num = num;

	if (s)
	{
		new->s = str_dupl(s);
		if (!new->s)
		{
			free(new);
			return (NULL);
		}
	}
	new->next = *head;
	*head = new;
	return (new);
}

/**
 * add_end - adds node at the end of the linked list
 * @head: address to the head node
 * @s: string of the node
 * @n: node index
 *
 * Return: the size of the list
 */

list_t *add_end(list_t **head, const char *s, int n)
{
	list_t *new, *node;

	if (!head)
		return (NULL);

	node = *head;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	set_mem((void *)new, 0, sizeof(list_t));
	new->num = n;
	if (s)
	{
		new->s = str_dupl(s);
		if (!new->s)
		{
			free(new);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new;
	}
	else
		*head = new;
	return (new);
}

/**
 * print_liststr - prints the string of a list_t list
 * @p: pointer address to the first node
 *
 * Return: the size of the list
 */

size_t print_liststr(const list_t *p)
{
	size_t n = 0;

	while (p)
	{
		_puts(p->s ? p->s : "(nil)");
		_puts("\n");
		p = p->next;
		n++;
	}
	return (n);
}

/**
 * delete_node_indx - deletes node at the given index
 * @head: pointer to the first node
 * @indx: the index node to delete
 *
 * Return: 1 on success, 0 on failure
 */

int delete_node_indx(list_t **head, unsigned int indx)
{
	list_t *node, *prev;
	unsigned int n = 0;

	if (!head || !*head)
		return (0);

	if (!indx)
	{
		node = *head;
		*head = (*head)->next;
		free(node->s);
		free(node);
		return (1);
	}
	node = *head;

	while (node)
	{
		if (n == indx)
		{
			prev->next = node->next;
			free(node->s);
			free(node);
			return (1);
		}
		n++;
		prev = node;
		node = node->next;
	}
	return (0);
}

/**
 * _freelist - frees all the nodes in the linked list
 * @head: pointer to the head node
 */

void _freelist(list_t **head)
{
	list_t *node, *next_node;

	if (!head || !*head)
		return;

	node = *head;

	while (node)
	{
		next_node = node->next;
		free(node->s);
		free(node);
		node = next_node;
	}
	*head = NULL;
}
