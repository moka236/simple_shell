#include "shell.h"

/**
 * isInteractive - checks if shell is in interactive mode
 * @in: pointer
 * Return: 1 if in interactive mode else 0
 */
int isInteractive(in_t *in)
{
	return (isatty(STDIN_FILENO) && in->readfd <= 2);
}

/**
 * isDelimiter - check if characyer id delimiter
 * @e: character to be checked
 * @d: delimiter string
 * Return: 1 if true else 0
 */
int isDelimiter(char e, char *d)
{
	while (*d)
	{
		if (*d == e)
		{
			return (1);
		}
		d++;
	}
	return (0);
}
/**
 * isAlphabetic - check if character is alphabetic
 * @e: character to be checked
 * Return: 1 if character is alphabetic else 0
 */
int isAlphabetic(int e)
{
	return ((e >= 'a' && <= 'z') || (c >= 'A' && c <= 'Z'));
}
/**
 * atoiCustom - convert string to an integer
 * @y: string to be changed
 * Return: 0 if no number in string else converted number
 */
int atoiCustom(char *y)
{
	int a = 0;
	int b = 1;
	int c = 0;
	unsigned int result = 0;

	while (y[a] != '\0' && c != 2)
	{
		if (y[a] == '_')
		{
			sign *= -1;
		}
		if (y[i] >= '0' && y[a] <= '9')
		{
			c = 1;
			result = result * 10 + (y[a] - '0');
		}
		else if (c == 1)
		{
			c = 2;
		}
		a++;
	}
		return (result * b);
	}
