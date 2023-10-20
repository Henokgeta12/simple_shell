#include "sshell.h"
/**
 * main - shell
 * @ac: arg count
 * @av: arg vect
 * @env: environ
 * Return: return
 */
int main(int ac, char **av, char **env)
{
	char *buff;
	char *cmd;
	char **args;
	size_t buff_size;/*buffer size*/
	pid_t c_pid;/*process to be forked*/
	int status, n_read;

	(void)ac;
	(void)av;
	buff = NULL;
	buff_size = 0;

	while (1)
	{
		write(1, "$ ", 2);/*prints the prompt*/
		fflush(stdout);
		n_read = getline(&buff, &buff_size, stdin);/*reads input from user*/
		if (n_read == -1)
		{
			write(1, "\n", 1);/*write a new line and exits*/
			exit(1);
		}
		buff[strcspn(buff, "\n")] = '\0';
		args = split_string(buff, " \t\n");/*tokenized*/
		c_pid = fork();/*create child process*/
		if (c_pid == 0)/*if child process*/
		{
			cmd = get_cmmd(args[0]);/*the command written by the user*/
			if (cmd)/*if command exist, then execute it*/
				execve(cmd, args, env);
			else
				printf("command not found\n");
			exit(0);
		}
		else/*if parent, then wait for child to finish*/
			wait(&status);
	}
	return (0);
}
