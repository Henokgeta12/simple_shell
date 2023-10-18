#include "shell.h"
/**
 * exec_process - form a new pid
 * @s: array given
 * Return: 0 sucess
 */
int exec_process(char **s)
{
	int a = 0, b = 0;
	pid_t new_pid = 0;

	new_pid = fork();
	if (new_pid == -1)
		result_prompt("failed\n", 7);
	else if (new_pid == 0)
	{
		b = execve(s[0], s, environ);
		if (b == -1)
		{
			b = 126;
			perror("hsh");
			exit(b);
		}
		exit(0);
	}
	else
		wait(&a);
	b = WEXITSTATUS(a);
	return (b);
}
/**
 * handle_environ - access global variable
 * @stat_inputs: variable from global environ
 * Return: content of the variable
 */
char *handle_environ(char *stat_inputs)
{
	char *a, *b, *c;
	const char checker[] = "=";
	int num = 0;

	if (stat_inputs != NULL)
	{
		if (environ == NULL)
			return (NULL);
		b = case_sense(environ[num]);
		while (b != NULL)
		{
			a = strtok(b, checker);
			if (comp_command(a, stat_inputs) == 0)
			{
				a = strtok(NULL, checker);
				c = case_sense(a);
				free(b);
				return (c);
			}
			++num;
			free(b);
			b = case_sense(environ[num]);
		}
	}
	return (NULL);
}
