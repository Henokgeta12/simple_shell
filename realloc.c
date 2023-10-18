#include "main.h"

/**
 * set_mem - fills the memory with a constant byte
 * @s: pointer to the memory area
 * @byte: the byte to fill the pointer with
 * @num: the amount of bytes to be filled
 *
 * Return: a pointer to the memory area
 */

char *set_mem(char *s, char byte, unsigned int num)
{
	unsigned int a;

	for (a = 0; a < num; a++)
		s[a] = byte;
	return (s);
}

/**
 * _free - frees a string of strings
 * @p: a string
 */

void _free(char *p)
{
	char *k = p;

	if (!p)
		return;
	while (*p)
		free(k++);
	free(k);
}

/**
 * my_realloc - reallocates a block of memory
 * @ptr: pointer to the previously allocated block
 * @old: the byte size of the previous block
 * @new: the byte size of the new block
 *
 * Return: pointer to the old block
 */

void *my_realloc(void *ptr, unsigned int old, unsigned int new)
{
	char *k;

	if (!ptr)
		return (malloc(new));
	if (!new)
		return (free(ptr), NULL);
	if (new == old)
		return (ptr);

	k = malloc(new);

	if (!k)
		return (NULL);

	old = old < new ? old : new;

	while (old--)
		k[old] = ((char *)ptr)[old];
	free(ptr);

	return (k);
}
