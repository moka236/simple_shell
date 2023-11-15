#include "shell.h"
/**
 * _eputs - prints intput to stderr
 * @str: string to be printed
 * Return: void
 */
void _eputs(char *str)
{

	if (!str)
		return;
	while (*str)
	{
		_eputchar(str++);
	}
}
/**
 * _eputchar - writes the character c to stderr
 * @c: the character to print
 * Return: 1 on success error -1
 */
int _eputchar(char c)
{
	static int count;

	count = 0;

	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || count >= WRITE_BUF_SIZE)
	{
		if (write(2, buf, count) == -1)
		{
			perror("_eputchar");
			return (-1);
		}
		count = 0;
	}
	if (c != BUF_FLUSH)
		buf[count++] = c;

	return (1);
}

/**
 * _putfd - writes the character u to fd
 * @c: character to be print
 * @fd: file descriptor to write
 * Return: 1 for success , -1 for error
 */
int _putfd(char c, int fd)
{
	static int count;

	count = 0;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || count >= WRITE_BUF_SIZE)
	{
		if (write(fd, buf, count) == -1)
		{
			perror("_putfd");
			return (-1);
		}
		count = 0;
	}
	if (c != BUFF_FLUSH)
		buf[count++] = c;
	return (1);
}

/**
 * _putsfd - print an input string
 * @str: string to be printed
 * @fd: file describtion
 * Return: number of char written
 */
int _putsfd(char *str, int fd)
{
	int count = 0;

	if (!str)
		return (0);

	while (*str)
	{
		count += _putfd(*str++, fd);
	}
	return (count);
}
