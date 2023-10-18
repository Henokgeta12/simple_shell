#include "main.h"

/**
 * interactive - deplays an active shell
 * @info: adress
 * Return: 1 if active else 0
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->read_fd <= 2);
}

/**
 * _delimeter - determines wether a charecter is a delimeter
 * @c: value to check
 * @delimeter: checks charecter
 * Return: 1 Success else 0 if faled
 */

int _delimeter(char c, char *delimeter)
{
	while (*delimeter)
		if (*delimeter++ == c)
			return (1);
	return (0);
}

/**
 * _alpha - determines an alphabet
 * @c: value to insert
 * Return: 1 (Success) else 0 failed
 */

int _alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - changes string to integers
 * @s: string to change
 * Return: changed number else 0 if failed
 */

int _atoi(char *a)
{
	int t, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (t = 0; a[t] != '\0' && flag != 2; t++)
	{
		if (a[t] == '-')
			sign *= -1;

		if (a[t] >= '0' && a[t] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (a[t] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
