#include "main.h"

/**
 * token - splits a string into words using a specified delimeter
 * @str: the input string
 * @del: the delimeter string
 *
 * Return: pointer to an array of strings
 */

char **token(char *str, char *del)
{
	int a, b, n, m, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!_delimeter(str[a], del) && (_delimeter(str[a + 1], del) || !str[a + 1]))
			num_words++;

	if (num_words == 0)
		return (NULL);
	s = malloc((num_words + 1) * sizeof(char *));

	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < num_words; b++)
	{
		while (_delimeter(str[a], del))
			a++;
		n = 0;

		while (!_delimeter(str[a + n], del) && str[a + n])
			n++;
		s[b] = malloc((n + 1) * sizeof(char));

		if (!s[b])
		{
			for (n = 0; n < b; n++)
				free(s[n]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < n; m++)
			s[b][m] = str[a++];
		s[b][m] = 0;
	}
	s[b] = NULL;
	return (s);
}

/**
 * tokenizer - splits a string into words using a specified delimeter
 * @str: the input string
 * @del: the delimeter used for splitting
 *
 * Return: pointer to an array of strings
 */

char **tokenizer(char *str, char *del)
{
	int a, b, k, m, num_words = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != *del && str[a + 1] == *del) ||
				(str[a] != *del && !str[a + 1]) || str[a + 1] == *del)
			num_words++;
	if (num_words == 0)
		return (NULL);
	s = malloc((num_words + 1) * sizeof(char *));

	if (!s)
		return (NULL);
	for (a = 0, b = 0; b < num_words; b++)
	{
		while (str[a] != '\0' && str[a] == *del)
			a++;
		k = 0;

		while (str[a + k] != *del && str[a + k] && str[a + k] != *del)
			k++;
		s[b] = malloc((k + 1) * sizeof(char));
		if (!s[b])
		{
			for (k = 0; k < b; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[b][m] = str[a++];
		s[b][m] = 0;
	}
	s[b] = NULL;
	return (s);
}
