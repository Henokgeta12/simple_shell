#include "shell.h"
/**
 * confirm_paths - confirm if oommand given can be exec
 * @s: inputs given
 * Return: 0 sucess
 */
int confirm_paths(char **s)
{
	char *a[121];
	int checker = -1, num = 0;
	char *old_path = NULL;
	char *new_path = NULL;
	char *file_loc = NULL;
	char *built_in_loc = NULL;

	old_path = handle_environ("PATH");
	if (old_path == NULL)
		return (-1);
	new_path = (case_sense(old_path));
	file_loc = strtok(new_path, ": ");
	if (file_loc == NULL)
		return (-1);
	free(old_path);
	while (checker == -1 && file_loc != NULL)
	{
		built_in_loc = handle_builtin(file_loc, s[0]);
		a[num] = built_in_loc;
		checker = opt_out_cmd(a[num]);
		file_loc = strtok(NULL, ":");
		num++;
	}
	num--;
	free(new_path);
	delete_mem(a, num);
	if (checker == 0)
	{
		s[0] = a[num];
		return (0);
	}
	else
	{
		free(a[num]);
		return (-1);
	}

}
