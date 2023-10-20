#include "sshell.h"
/**
 * get_cmmd - gets the full path of the command typed by the user
 * @comm: The command typed by the user
 *
 * Return: full path
 */
char *get_cmmd(char *comm)
{
	char *path = g_envi("PATH");
	char *tokken;
	char *com_ful_path;
	struct stat st;

	if (strchr(comm, '/') != NULL)
	{
		return (strdup(comm));
	}

	tokken = strtok(path, ":");
	while (tokken)
	{
		com_ful_path = malloc(strlen(tokken) + strlen(comm) + 2);
		strcpy(com_ful_path, tokken);
		strcat(com_ful_path, "/");
		strcat(com_ful_path, comm);
		if (stat(com_ful_path, &st) == 0)
			return (com_ful_path);
		free(com_ful_path);
		tokken = strtok(NULL, ":");
	}
	return (NULL);
}
