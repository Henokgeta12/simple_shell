#include "main.h"
/**
 * is_empty - checks for spaces without command
 * @str - string to test
 * Return: true
 */

bool is_empty(const char *str)
{
	size_t i;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] != ' ')
		{
			return false;
		}
	}
	return true;
}
