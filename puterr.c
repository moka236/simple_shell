#include "shell.h"
/**
 * _eputs - prints intput to stderr
 * @str: string to be printed
 * Return: void
 */
void _eputs(char *str)
{
	int y = 0;

	if (!str)
		return;
	while (str[y] != '\0')
	{
		_eputchar(str[y]);
		y++;
	}
}
/**
 * _eputchar - writes the character c to stderr
 * @u: the character to print
 * Return: 1 on success error -1
 */
int _eputchar(char u)
{
	static int c;
	static char buf[WRITE_BUF_SIZE];

	if (u == BUF_FLUSH || c >= WRITE_BUF_SIZE)
	{
		if (write(2, buf, c) == -1)
		{
			return (-1);
		}
		c = 0;
	}
	if (u != BUF_FLUSH)
		buf[c++] = u;

	return (1);
}

/**
 * _putfd - writes the character u to fd
 * @u: character to be print
 * @fd: file descriptor to write
 * Return: 1 for success , -1 for error
 */
int _putfd(char u, int fd)
{
	static int t;
	static char buf[WRITE_BUF_SIZE];

	if (u == BUF_FLUSH || t >= WRITE_BUF_SIZE)
	{
		if (write(fd, buf, t) == -1)
		{
			return (-1);
		}
		t = 0;
	}
	if (u != BUFF_FLUSH)
		buf[t++] = u;
	return (1);
}

/**
 * _putsfd - print an input string
 * @str: string to be printed
 * @fd: file describtion
 * Return: number of char written
 */
int _uptsfd(char *str, int fd)
{
	int o = 0;

	if (!str)
		return (0);

	while (*str)
	{
		o += _putfd(*str++, fd);
	}
	return (o);
}
