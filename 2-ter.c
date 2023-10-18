#include "shell.h"
/**
 * opt_out_last - release memory of last program
 * @array: input given
 */
void opt_out_last(char *array)
{
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(array);
	}
	if (!isatty(STDIN_FILENO))
		free(array);
}
/**
 * error_message - print if the command are error
 * @s: array given
 * @add: number of time
 * Return: status
 */
int error_message(char **s, int add)
{
	char *not_inter = "./hsh";
	char *inter = "hsh";

	if (isatty(STDIN_FILENO))
	{
		write(2, inter, 3);
	}
	else
	{
		write(2, not_inter, 5);
	}
	write(2, ": ", 2);
	count_digits(add);
	write(2, ": ", 2);
	write(2, s[0], size_cmd(s[0]));
	write(2, ": not found\n", 12);
	return (127);
}
/**
 * result_prompt - result of the prompt
 * @num: string to print
 * @len: size of the string
 * Return: 0 sucess
 */
int result_prompt(const char *num, unsigned int len)
{
	int n;

	if (isatty(STDIN_FILENO))
	{
		n = write(1, num, len);
		if (n == -1)
		{
			return (-1);
		}
	}
	return (0);
}
