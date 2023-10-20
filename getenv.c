#include "sshell.h"
/**
 * g_envi - gets the path and returns it
 * @ev_varia: environment var
 *
 * Return: path
 */
char *g_envi(const char *ev_varia)
{
	int i = 0;/*index*/
	char *keyy;/*variable for the search*/

	while (environ[i])
	{
		keyy = strtok(environ[i], "=");
		if (strcmp(ev_varia, keyy) == 0)
			return (strtok(NULL, "\n"));/*if yes, continue*/
		i++;
	}
	return (NULL); /*if env var not found return null*/
}
