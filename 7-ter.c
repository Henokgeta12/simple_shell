#include "shell.h"
/**
 * confirm_cmd - check the command passed
 * @s: point to array given
 * @check: status
 * Return: -1 if command is not valis
 */
int confirm_cmd(char **s, int check)
{
	char *apply_cmd[2] = {
		"exit",
		"env"
	};
	int ch = 0;

	while (ch < 2)
	{
		if (comp_command(s[0], apply_cmd[ch]) == 0)
			break;
		ch++;
	}
	if (ch == 2)
		return (-1);
	if (comp_command(apply_cmd[ch], "exit") == 0)
	{
		free(s[0]);
		exit(check);
	}
	if (comp_command(apply_cmd[ch], "env") == 0)
	{
		if (environ == NULL)
			return (0);
		write(1, environ, 1000);
	}
	return (0);
}
