#include "main.h"

/**
 * inp_buffer - commands
 * @info: parameter
 * @buff: address
 * @len: length
 * Return: bytes
 */

ssize_t inp_buffer(info_t *info, char **buff, size_t *len)
{
	ssize_t o = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		o = getline(buffer, &len_p, stdin);
#else
		o = my_getline(info, buff, &len_p);
#endif
		if (o > 0)
		{
			if ((*buff)[o - 1] == '\n')
			{
				(*buff)[o - 1] = '\0';
				o--;
			}
			info->lcount_flag = 1;
			rm_comment(*buff);
			build_histlist(info, *buff, info->histcount++);
			{
				*len = o;
				info->command_buff = buff;
			}
		}
	}
	return (o);
}

/**
 * _getinput - atains input without a newline
 * @info: parameter
 * Return: bytes
 */

ssize_t _getinput(info_t *info)
{
	static char *buffer;
	static size_t a, n, leng;
	ssize_t k = 0;
	char **buffer_p = &(info->arg), *y;

	_putchar(BUFF_FLUSH);
	k = inp_buffer(info, &buffer, &leng);
	if (k == -1)
		return (-1);
	if (leng)
	{
		n = a;
		y = buffer + a;

		_chain(info, buffer, &n, a);
		while (n < leng)
		{
			if (_chain(info, buffer, &n, leng))
				break;
			n++;
		}

		a = n + 1;
		if (a >= leng)
		{
			a = leng = 0;
			info->command_buff_type = COMMAND_NORM;
		}

		*buffer_p = y;
		return (_strlen(y));
	}

	*buffer_p = buffer;
	return (k);
}

/**
 * read_buffer - reads buffer
 * @info: parameter
 * @buf: buffer
 * @i: size
 * Return: a
 */

ssize_t read_buffer(info_t *info, char *buf, size_t *i)
{
	ssize_t a = 0;

	if (*i)
		return (0);
	a = read(info->read_fd, buf, BUFFER_SIZE);
	if (a >= 0)
		*i = a;
	return (a);
}

/**
 * my_getline - retrives line of input
 * @info: parameter
 * @ptr: pointer
 * @length: length of ptr
 * Return: a
 */

int my_getline(info_t *info, char **ptr, size_t *length)
{
	static char *buff;
	static size_t t, leng;
	size_t p;
	ssize_t b = 0, a = 0;
	char *q = NULL, *new_d = NULL, *l;

	q = *ptr;
	if (q && length)
		a = *length;
	if (t == leng)
		t = leng = 0;

	b = read_buffer(info, buff, &leng);
	if (b == -1 || (b == 0 && leng == 0))
		return (-1);

	l = str_char(buff + t, '\n');
	p = l ? 1 + (unsigned int)(l - buff) : leng;
	new_d = my_realloc(q, a, a ? a +  p : p + 1);
	if (!new_d)
		return (q ? free(q), -1 : -1);

	if (a)
		strn_cat(new_d, buff + t, p - t);
	else
		strn_cpy(new_d, buff + t, (p - t + 1));

	l += p - t;
	t = p;
	q = new_d;	
	*ptr = l + 1;

	if (length)
		*length = *l;
	*ptr = q;
	return (a);
}

/**
 * sigintHandler - handles sinals
 * @signum: signal no.
 * Return: none
 */

void sigintHandler(__attribute__((unused))int signum)
{
	_puts("\n");
	_puts("$");
	_putchar(BUFF_FLUSH);
}
