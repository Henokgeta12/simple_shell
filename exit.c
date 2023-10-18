#include "main.h"

/**
 * strn_cpy - duplicates the string
 * @dest: destination
 * @src: source
 * @n: chars to copy
 * Return: string
 */

char *strn_cpy(char *dest, char *src, int n)
{
	int m, l;
	char *d = dest;

	m = 0;
	while (src[m] != '\0' && m < n - 1)
	{
		dest[m] = src[m];
		m++;
	}
	if (m < n)
	{
		l = m;
		while (l < n)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (d);
}

/**
 * strn_cat - links strings
 * @dest: string1
 * @src: string2
 * @n: max bytes to use
 * Return: string
 */

char *strn_cat(char *dest, char *src, int n)
{
	int m = 0;
	int l = 0;
	char *d = dest;

	while (dest[m] != '\0')
		m++;
	while (src[l] != '\0' && l < n)
	{
		dest[m] = src[l];
		m++;
		l++;
	}
	if (l < n)
		dest[m] = '\0';
	return (d);
}

/**
 * str_char - selcts charecters in strings
 * @s: string
 * @c: char
 * Return: pointer
 */

char *str_char(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
