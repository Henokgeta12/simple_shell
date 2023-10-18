#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: the string to check
 *
 * Return: integer length of a string
 */

int _strlen(char *str)
{
	int n = 0;

	if (!str)
		return (0);
	while (*str++)
		n++;
	return (n);
}

/**
 * _strcmp - compares two strings
 * @str1: the first string
 * @str2: the second string
 *
 * Return: - if str1 < str2, + if str1 > str2, 0 if str1 == str2
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * start_with - checks if the string haystack starts with the substring needle
 * @hay: the string to search
 * @ndle: the substring to find
 *
 * Return: address of next char in haystack or NULL
 */

char *start_with(const char *hay, const char *ndle)
{
	while (*ndle)
		if (*ndle++ != *hay++)
			return (NULL);
	return ((char *)hay);
}

/**
 * _strcat - concatenates two strings
 * @des: destination buffer
 * @s: source buffer
 *
 * Return: pointer to the dest
 */

char *_strcat(char *des, char *s)
{
	char *ret = des;

	while (*des)
		des++;
	while (*s)
		*des++ = *s++;
	*des = *s;

	return (ret);
}
