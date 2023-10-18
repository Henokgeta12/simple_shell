#include "main.h"

/**
 * strings_equal - Compare two strings
 * @str1: First string
 * @str2: Second string
 * Return: 1 if strings are equal, 0 if not
 */
int strings_equal(const char *str1, const char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (0);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (0);
	str1++;
	str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return (1);
	else
		return (0);
}

/**
 * str_length - Compute the length of a string
 * @str: Input string
 * Return: Length of the string
 */
int str_length(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * my_exit - Handle the "exit" command
 * @input: User input
 */
void my_exit(char *input)
{
	if (strings_equal(input, "exit"))
	{
		_exit(0);
	}
	else
	{
		const char *exit_prefix = "exit ";
		int prefix_len = str_length(exit_prefix);

		if (str_length(input) > prefix_len && strings_equal(input, exit_prefix))
		{
			int exit_status = atoi(input + prefix_len);

			_exit(exit_status);
		}
		else
		{
			const char *unknown_cmd = "Unknown command: ";

			write(STDOUT_FILENO, unknown_cmd, str_length(unknown_cmd));
			write(STDOUT_FILENO, input, str_length(input));
			write(STDOUT_FILENO, "\n", 1);
		}
	}
}

/**
 * print_env - executes the builtin env
 * Return: 0
 */

void print_env(void)
{

	char **env = environ;

	while (*env != NULL)
	{
		char *env_var = *env;

		while (*env_var != '\0')
		{
			write(STDOUT_FILENO, env_var, 1);
			env_var++;
		}
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
