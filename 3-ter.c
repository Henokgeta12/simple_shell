#include "shell.h"
/**
 * comp_command - to compare strings
 * @s1: strings
 * @s2: strings
 * Return: 0 sucess
 */
int comp_command(char *s1, char *s2)
{
	int len;

	for (len = 0; s1[len] != '\0'; len++)
		;
	for (len = 0; s2[len] != '\0'; len++)
	{
		if (s1[len] != s2[len])
		{
			return (s1[len] - s2[len]);
		}
	}
	return (0);
}

/**
 * case_sense - Create a new pre- strings
 * @s: string
 * Return: to the pre-string
 */
char *case_sense(char *s)
{
	char *check;
	unsigned int n, size;

	if (s == NULL)
		return (NULL);
	for (size = 0; s[size] != '\0'; size++)
		;
	check = (char *)malloc(sizeof(char) * (size + 1));
	if (check == NULL)
		return (NULL);
	for (n = 0; n <= size; n++)
	{
		check[n] = s[n];
	}
	return (check);
}
/**
 * size_cmd - size of the strings
 * @arr: strings
 * Return: the size of the string
 */
int size_cmd(const char *arr)
{
	int size = 0;

	if (arr == NULL)
		return (0);
	while (arr[size] != '\0')
		size++;
	return (size++);
}
