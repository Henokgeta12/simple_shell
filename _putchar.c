#include "shell.h"
/**
 * _putchar - to write the character to the standard output
 * @ch: the input
 * Return: 0 sucess
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

