#include "shell.h"
/**
 * _erratoi - convert string to an integer
 * @t: string to be converted
 * Return: 0 else -1 for error
 */
int _erratoi(char *t)
{
	int u;
	unsigned long int result = 0;

	for (u = 0; t[u] >= '0' && t[u] <= '9'; u++)
	{
		result *= 10;
		result += (t[u] - '0');
		if (result > INT_MAX)
			return (-1);
	}
	return (result);
}
/**
 * print_d - function print integer number
 * @input: input
 * @fd: file description
 * Return: number of character printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = (fd == STDERR_FILENO) ? _putchar : _putchar;
	size_t i;
	unsigned int current = abs(input);
	int count = 0;

	if (input < 0)
	{
		__putchar('-');
		count++;
	}

	for (i = 1000000000; i > 1 && current != 0; i /= 10)
	{
		__putchar('0' + current / i);
		count++;
		current %= i;
	}
	__putchar('0' + current);
	count++;
	return (count);
}

/**
 * convert_number - convert function
 * @num: number
 * @base: base
 * @flags: argument
 * Return: converted number
 */
char *convert_number(long int num, int base, int flags)
{
	static char buffer[BUFFER_SIZE];
	char *ptr = &buffer[BUFFER_SIZE - 1];

	return (ptr);
}
