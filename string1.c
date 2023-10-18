#include "main.h"

/**
 * str_copy - copies content of the source to destination string
 * @d: the destination string
 * @s: source string
 *
 * Return: pointer to the destination
 */

char *str_copy(char *d, char *s)
{
	int i = 0;

	if (d == s || s == 0)
		return (d);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = 0;

	return (d);
}

/**
 * str_dupl - duplicates a string
 * @s: the string to duplicate
 *
 * Return: pointer to the duplicatd string
 */

char *str_dupl(const char *s)
{
	int leng = 0;
	char *ret;

	if (s == NULL)
		return (NULL);
	while (*s++)
		leng++;

	ret = malloc(sizeof(char) * (leng + 1));
	if (!ret)
		return (NULL);
	for (leng++; leng--;)
		ret[leng] = *--s;

	return (ret);
}

/**
 * _puts - prints an input string
 * @s: the string to be printed
 */

void _puts(char *s)
{
	int n = 0;

	if (!s)
		return;
	while (s[n] != '\0')
	{
		_putchar(s[n]);
		n++;
	}
}

/**
 * _putchar - writes the character to the standard output
 * @chr: the character to print
 *
 * Return: 0 on success, -1 on error
 */

int _putchar(char chr)
{
	static int n;
	static char buffer[WRITE_BUFF_SIZE];

	if (chr == BUFF_FLUSH || n >= WRITE_BUFF_SIZE)
	{
		write(1, buffer, n);
		n = 0;
	}
	if (chr != BUFF_FLUSH)
		buffer[n++] = chr;
	return (1);
}
