#include "shell.h"
/**
 * opt_out_cmd - to check if a file is still running
 * @file: file
 * Return: 0 sucess
 */
int opt_out_cmd(char *file)
{
	int checker;

	checker = (open(file, O_RDONLY));
	if (checker != -1)
	{
		close(checker);
		return (0);
	}
	else
		return (-1);
}
/**
 * list_inputs - list of input in an array
 * @arr1: variable to put in array
 * @arr2: the total array
 * Return: size of the array
 */
int list_inputs(char *arr1, char **arr2)
{
	char *list_array;
	char *mem = arr1, *built_in;
	int num = 0;

	built_in = strtok(arr1, "\n\t\r ");
	arr2[num] = built_in;
	while (mem != NULL)
	{
		++num;
		list_array = strtok(NULL, "\n\t\r ");
		mem = list_array;
		arr2[num] = list_array;
	}
	arr2[num] = NULL;
	return (num);
}
/**
 * delete_mem - delete memory occupied
 * @array: srray
 * @size: size of the array
 */
void delete_mem(char **array, int size)
{
	int num = 0;

	if (array == NULL)
		return;
	while (num < size)
	{
		free(array[num]);
		num++;
	}
}

