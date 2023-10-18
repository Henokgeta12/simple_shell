/**
* print_prompt - peints the prompt
* Return: NULL
*/

#include "main.h"
int print_prompt(void)
{
	char *prompt;

	prompt = ":) ";

	write(STDOUT_FILENO, prompt, 3);
	return (0);
}


/**
 * get_cmd_line -  getcommand
 * Reads a line of input from the user.
 * Return: address of buf
 * A pointer to the line of input, or NULL if there was an error.
 */
char *get_cmd_line()
{
	ssize_t chars_read;
	size_t n;
	char *buf = NULL;

	chars_read = getline(&buf, &n, stdin);
	if (chars_read == -1)
	{
		perror("Exiting the shell ;)");
		free(buf);
		exit(0);
	}
	if (buf[chars_read - 1] == '\n')
	{
		buf[chars_read - 1] = '\0';
	}
	return (buf);
}

/**
 * tokenize_cmd_line - Tokenizes a command line into an array of strings.
 * @cmd_line: The command line to tokenize.
 * @delimeter: The delimiter to use when tokenizing the command line.
 * Return: A pointer to an array of strings.
 */
char **tokenize_cmd_line(char *cmd_line, char *delimiter)
{
	int number_tokens = 0;
	char *token, *end;
	char **argv;
	int i, j;

	i = 0;
	token = strtok(cmd_line, delimiter);

	while (token != NULL)
	{
		number_tokens++;
		token = strtok(NULL, delimiter);
	}

	argv = malloc(sizeof(char *) * (number_tokens + 1));

	if (argv == NULL)
	{
		perror("malloc for argv failed");
		return (NULL);
	}

	token = strtok(cmd_line, delimiter);
	i = 0;

	while (token != NULL)
	{
		while (*token == ' ' || *token == '\t')
			token++;
		end = token + strlen(token) - 1;
		while (end > token && (*end == ' ' || *end == '\t'))
			end--;
		end[1] = '\0';
		argv[i] = strdup(token);

		if (argv[i] == NULL)
		{
			perror("malloc for string failed");
			for (j = 0; j < i; j++)
				free(argv[i]);

			free(argv);
			return (NULL);
		}

		token = strtok(NULL, delimiter);
		i++;
	}

	argv[i] = NULL;
	return (argv);
}


#include "main.h"

#include "main.h"

/**
 * execute_command - Execute a command with its arguments.
 * @argv: Array of strings (command and arguments)
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char **argv, char **env)
{
	pid_t child_pid;
	int status;
	char *actual_command, *command;

	actual_command = NULL;
	if (!argv)
	{
		perror("no command input");
		return (0);
	}
	else
	{
		command = argv[0];

		actual_command = find_path(command);
		if (actual_command == NULL)
		{
			perror("path not found");
			return (0);
		}

		child_pid = fork();
		if (child_pid < 0)
		{
			perror("Error in creating child process");
			return (-1);
		}
		else if (child_pid == 0)
		{
			if (execve(actual_command, argv, env) == -1)
			{
				perror("No file or directory");
				return (0);
			}
			return (0);
		}
		else
		{
			waitpid(child_pid, &status, 0);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				return (0);
			write(STDOUT_FILENO, "\n", 1);
		}

	}
	free(actual_command);
	return (0);
}



/**
* main - main function
* @argc: number of arguments
* @argv: string of argumnets;
* @envp: environment variables
* Return: always 0
*/

int main(int argc, char **argv, char **env)
{
	char *cmd_line;
	int status;
	char *delimeter;
	bool is_pipe;


	is_pipe = false;

	delimeter = " ";

	while (true && !is_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			is_pipe = true;

		print_prompt();
		cmd_line  = get_cmd_line();
		if (is_empty(cmd_line))
		{
			free(cmd_line);
			continue;
		}

		if (argv && argv[0])
		{
			argv = tokenize_cmd_line(cmd_line, delimeter);
			if (strings_equal(argv[0], "exit"))
			{
				my_exit(argv[0]);
				free(cmd_line);
				free(argv);
				break;
			}
			(strings_equal(argv[0], "env"));
			{
				print_env();
			}
		}

		if (cmd_line == NULL)
			return (0);
		if (argv == NULL)
			break;
		if (argc)
			status = execute_command(argv, env);
		if (status != 0)
		{
			free(argv);
			return (0);
		}
	}
	free(cmd_line);
	if (argv != NULL)
		free(argv);
	return (0);
}
