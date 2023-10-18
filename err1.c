#include "main.h"

/**
 * err_atoi - changes strings to integers
 * @r: string to change
 * Return: 0 if string else -1 if error
 */

int err_atoi(char *r)
{
	int a = 0;
	unsigned long int resl = 0;

	if (*r == '+')
		r++; /* TODDO: why does this return main 255? */
	for (r = 0; r[a] != '\0'; a++)
	{
		if (r[a] >= '0' && r[a] <= '9')
		{
			resl *= 10;
			resl += (r[a] - '0');
			if (resl > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (resl);
}

/**
 * _printerror - returns error message
 * @info: parameter
 * @erstr: specific error types
 *
 * Return: 0 if string else -1 if failed
 */

void _printerror(info_t *info, char *erstr)
{
	_eputs(info->fl_name);
	_eputs(": ");
	print_dec(info->l_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(erstr);
}

/**
 * print_d returns the decimal
 * @input: input
 * @fd: file descriptor
 * Return: printed outcome
 */

int print_d(int input, int fd)
{
	int (*___putchar)(char) = _putchar;
	int l, coun = 0;
	unsigned int _abs_, curr;

	if (fd == STDERR_FILENO)
		___putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		___putchar('-');
		coun++;
	}
	else
		_abs_ = input;
	curr = _abs_;
	for (l = 1000000000; l > 1; l /= 10)
	{
		if (_abs_ / l)
		{
			___putchar('0' + curr / l);
			coun++;
		}
		curr %= l;
	}
	___putchar('0' + curr);
	coun++;

	return (coun);
}

/**
 * convert_numb - a replica of atoi
 * @num: number to change
 * @base: base
 * @flags: flags
 * Return: converted string
 */

char *convert_num(long int num, int base, int flags)
{
	static char *arr;
	static char buffer[50];
	char sign = 0;
	char *point;
	unsigned long a = num;

	if (!(flags & CONV_UNSIGNED) && num < 0)
	{
		a = num;
		sign = '-';
	}

	arr = flags & CONV_LOWER ? "012356789abcdef" :
		"0123456789ABCDEF";
	point = &buffer[49];
	*point = '\0';

	do {
		*--point = arr[a % base];
		a /= base;
	} while (a != 0);

	if (sign)
		*--point = sign;
	return (point);
}

/**
 * rm_comment - delets comments
 * @buf: string to modify through adress
 * Return: 0 (Success)
 */

void rm_comment(char *buf)
{
	int s;

	for (s = 0; buf[s] != '\0'; s++)
		if (buf[s] == '#' && (!s || buf[s - 1] == ' '))
		{
			buf[s] = '\0';
			break;
		}
}
