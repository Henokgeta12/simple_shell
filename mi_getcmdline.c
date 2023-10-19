#include "mi-sh.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
size_t mi_strlen(char *str);

/**
 * mi_get_input - gets line for user input
 * Return:UserInput
 */

char *mi_get_input(void)
{
	char *user_in = NULL;
	size_t user_inSize = 0;

	if (isatty(STDIN_FILENO))
	{
		char cwd[1024];

		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
	}

	if (getline(&user_in, &user_inSize, stdin) == -1)
	{
		free(user_in);
		if (user_inSize == 0)
		{
			return (NULL);
		}
		else
		{
			perror("getline");
			return (NULL);
		}
	}

	return (user_in);
}

