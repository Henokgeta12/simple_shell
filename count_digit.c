#include "shell.h"
/**
 * count_digits - to count base 10 numbers
 * @num: numbers
 * Return: 0 sucess
 */
int count_digits(int num)
{
	for (num = 0; num <= 9; num++)
	{
		_putchar(num + '0');
	}
	_putchar('\n');
	return (0);
}
