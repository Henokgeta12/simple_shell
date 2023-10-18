#include "main.h"
/**
 * custom_strtok - Tokenize a string based on a delimiter
 * @str: The input string to be tokenized.
 * @delim: The delimiter used to split the string
 * @save_ptr: Maintain the position in the input string
 *
 * This function tokenizes the input string 'str; into smaller toke
 *
 * Return: A pointer to the next token found in string
 */
char *custom_strtok(char *str, const char *delim, char **save_ptr)
{
	char *token_start, *token_end;

	if (str == NULL && *save_ptr == NULL)
		return (NULL);
	token_start = (str != NULL) ? str : *save_ptr;
	token_end = strpbrk(token_start, delim);

	if (token_end != NULL)
	{
		token_end = '\0';
		*save_ptr = token_end + 1;
	}
	else
		*save_ptr = NULL;
	return (token_start);
}
