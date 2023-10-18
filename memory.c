#include "main.h"

/**
 * pfree - frees a pointer
 * @p: pointer address to free
 *
 * Return: 1 if freed, otherwise 0
 */

int pfree(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;

		return (1);
	}
	return (0);
}
