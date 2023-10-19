#include "mi-sh.h"
#include <stddef.h>
#include <unistd.h>
#include <string.h>
size_t mi_strlen(char *str);

/**
 * mi_display_environ - display and prints environ details
 * @environ: the environment to be shown
 * Return: nothing
 */

void mi_display_environ(char **environ)
{
	size_t ind = 0;

	while (environ[ind])
	{
		write(STDOUT_FILENO, environ[ind], mi_strlen(environ[ind]));
		write(STDOUT_FILENO, "\n", 1);
		ind++;
	}
}
