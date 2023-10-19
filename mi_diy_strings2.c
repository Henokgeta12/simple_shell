#include "mi-sh.h"

/**
 * mi_copy_string - copies the string pointed to by src into dest
 * @destz: destination of thestr to be copy
 * @srcz: source of thestr to be copy
 *
 * Return: char pointer to dest
 */

char *mi_copy_string(char *destz, char *srcz)
{
	int z = 0;

	for (z = 0; srcz[z] != '\0'; z++)
	{
		destz[z] = srcz[z];
	}
	destz[z] = '\0';
	return (destz);
}
