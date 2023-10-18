#include "shell.h"
/**
 * main - the main handling the shell implementations
 * Return: 0 if sucess
 */
int main(void)
{
	int checker = 1, verify_init = 0, verify_out = 0, verify_in = 0, hnd_cmd = 0;
	char *array = NULL, *s[20];
	ssize_t cal_size = 0;
	size_t buff_size = 0;

	result_prompt("$ ", 2);
	cal_size = getline(&array, &buff_size, stdin);
	while (cal_size != -1)
	{
		if (*array != '\n')
		{
			list_inputs(array, s);
			if (s[0] != NULL)
			{
				verify_out = opt_out_cmd(s[0]);
				if (verify_out != 0)
				{
					verify_init = confirm_paths(s);
					if (verify_init == 0)
						verify_in = exec_process(s), free(array), free(*s);
					else
					{
					hnd_cmd = confirm_cmd(s, verify_in);
					if (hnd_cmd != 0)
						verify_in = error_message(s, checker), free(array);
					}
				}
				else
					verify_in = exec_process(s), free(array);
			}
		else
			free(array);
		}
		else if (*array == '\n')
			free(array);
		array = NULL, checker++;
		result_prompt("$ ", 2), cal_size = getline(&array, &buff_size, stdin);
	}
	opt_out_last(array);
	return (verify_in);
}
