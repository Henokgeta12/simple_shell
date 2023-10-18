#include "main.h"

/**
 * _eputs - produces printots of strings
 * @s: string
 *
 * Return: None
 */

void _eputs(char *s)
{
	int t = 0;

	if (!s)
		return;

	while (s[t] != '\0')
	{
		_eputchar(s[t]);
		t++;
	}
}

/**
 * _eputchar - prints stderr using chatacter
 * @b: char to be printed
 * Return: 1 (Success) else -1 (failure)
 */

int _eputchar(char b)
{
	static int n;
	static char buff[WRITE_BUFF_SIZE];

	if (b == BUFF_FLUSH || n >= WRITE_BUFF_SIZE)
	{
		write(2, buff, n);
		n = 0;
	}
	if (b != BUFF_FLUSH)
		buff[n++] = b;
	return (1);
}

/**
 * _putfd - inserts char to fd
 * @k: char to be printed
 * @fd: file descritor
 * Return: 1 (Success) else -1 error
 */

int _putfd(char k, int fd)
{
	static int n;
	static char buffer[WRITE_BUFF_SIZE];

	if (k == BUFF_FLUSH || n >= WRITE_BUFF_SIZE)
	{
		write(fd, buffer, n);
		n++;
	}
	if (k != BUFF_FLUSH)
		buffer[n++] = k;
	return (1);
}

/**
 * _putsfd - displays a string
 * @s: string to be displayed
 * @fd: file descriptor
 * Return: numbber char inserted
 */

int _putsfd(char  *s, int fd)
{
	int m = 0;

	if (!s)
		return (0);
	while (*s)
	{
		m += _putfd(*s++, fd);
	}
	return (m);
}
