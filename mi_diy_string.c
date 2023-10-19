#include "mi-sh.h"
#include <stddef.h>

/**
 * mi_strlen - calculate the size of a string
 * @str: the string to calculate
 * Return: the length of the string calculated
 */

size_t mi_strlen(char *str)
{
	int z;

	for (z = 0; str[z] != 0; z++)
		;
	return (z);
}

/**
 * mi_strcomp - Compares two strings
 *
 * @str1: a string
 * @str2: string2
 *
 * Return: returns many things
 *
 */
size_t mi_strcomp(char *str1, char *str2)
{
	int z = 0;
	int calc;

	while (str1[z] != 0 && str2[z] != 0 && str1[z] == str2[z])
		z++;
calc = str1[z] - str2[z];
return (calc);

}

/**
 * mi_concat_strings - addes two strings
 *
 * @destz: Destination for string
 *
 * @srcz: Original string
 * Return: Always 0
 */
char *mi_concat_strings(char *destz, char *srcz)
{
	int z, y = 0;

	for (z = 0; destz[z] != '\0'; z++)
	{
	}
	for (y = 0; srcz[y] != '\0'; y++)
	{
		destz[z] = srcz[y];
		z++;

	}
	destz[z] = '\0';
return (destz);
}

/**
 *mi_strncomp - compares two strings.
 *@str1: string one
 *@str2: string two
 *@no: number of characters
 * Return: calculated diference
 */
size_t mi_strncomp(char *str1, char *str2, size_t no)
{
	size_t z;
	size_t y;

	if (str1 == NULL || str2 == NULL)
		return (0);
	for (y = 0; str1[y] != '\0' && y < no; y++)
	{
		z = str1[y] - str2[y];

		if (z != 0)
		{
			return (z);
		}
	}
	return (0);
}
