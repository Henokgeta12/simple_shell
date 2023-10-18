#include "main.h"

/**
 * hist_file - retrives history
 * @info: parameter
 * Return: String
 */

char *hist_file(info_t *info)
{
	char *buffer, *dir;

	dir = get_env(info, "HOME=");
	if (!dir)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(dir) + _strlen(HISTORY_FILE) + 2));
	if (!dir)
		return (NULL);
	buffer[0] = 0;
	str_copy(buffer, dir);
	strcat(buffer, "/");
	strcat(buffer, HISTORY_FILE);
	return (buffer);
}

/**
 * write_hist - creates the history
 * @info: argument
 * Return: 1 (Success) or -1 if failed
 */

int write_hist(info_t *info)
{
	ssize_t fd;
	char *filename = hist_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->hist; node; node = node->next)
	{
		_putsfd(node->s, fd);
		_putfd('\n', fd);
	}
	_putfd(BUFF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * _readhist - detects history in files
 * @info: parameter
 * Return: history
 */

int _readhist(info_t *info)
{
	int a, last = 0, l_count = 0;
	ssize_t fd, rdleng, fsize = 0;
	struct stat st;
	char *buffer = NULL, *filename = hist_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == (ssize_t)-1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
	{
		close(fd);
		return (0);
	}
	buffer = malloc(sizeof(char) * (fsize + 1));
	if (!buffer)
	{
		close(fd);
		return (0);
	}
	rdleng = read(fd, buffer, fsize);
	buffer[fsize] = 0;
	if (rdleng <= 0)
	{
		close(fd);
		return (free(buffer), 0);
	}
	close(fd);
	for (a = 0; a < fsize; a++)
		if (buffer[a] == '\n')
		{
			buffer[a] = 0;
			build_histlist(info, buffer + last, l_count++);
			last = a + 1;
		}
	if (last != a)
		build_histlist(info, buffer + last, l_count++);
	free(buffer);
	info->histcount = l_count;
	while (info->histcount >= HISTORY_MAXIMUM)
		delete_node_indx(&(info->hist), 0);
	renum_hist(info);
	return (info->histcount);
}

/**
 * build_histlist - creates history entry
 * @info: arguments
 * @buff: pointer to buffer
 * @lcount: number of lines in history list
 * Return: 0 (Success)
 */

int build_histlist(info_t *info, char *buff, int lcount)
{
	list_t *node = NULL;

	if (info->hist)
		node = info->hist;
	add_end(&node, buff, lcount);

	if (!info->hist)
		info->hist = node;
	return (0);
}

/**
 * renum_hist - numbers the list again
 * @info: arguments
 * Return: histcount
 */

int renum_hist(info_t *info)
{
	list_t *node = info->hist;
	int k = 0;

	while (node)
	{
		node->num = k++;
		node = node->next;
	}
	return (info->histcount = k);
}
