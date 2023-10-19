#include "mi-sh.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * mi_tokenize - splits string into smaller parts ie tokens
 * @user_in: user input to tokenize
 * Return:tokenized user input ie pointer to where it is
 */

char **mi_tokenize(char *user_in)
{
	size_t mi_strlen(char *str);
	char **user_cmd = NULL;
	char *tkn = NULL;
	size_t z = 0;
	int tkn_cnt = 0;

	if (user_in == NULL)
		return (NULL);

	for (z = 0; user_in[z]; z++)
	{
		if (user_in[z] == ' ')
			tkn_cnt++;
	}
	if ((size_t)(tkn_cnt + 1) == mi_strlen(user_in))
		return (NULL);

	user_cmd = (char **)malloc(sizeof(char *) * (tkn_cnt + 2));

	if (user_cmd == NULL)
		return (NULL);

	tkn = strtok(user_in, " \n\t\r");

	for (z = 0; tkn != NULL; z++)
	{
		user_cmd[z] = tkn;
		tkn = strtok(NULL, " \n\t\r");
	}

	user_cmd[z] = NULL;
	return (user_cmd);
}
