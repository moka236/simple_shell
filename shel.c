#include "main.h"

/**
 * interactive - returns true if shell is interactive mode
 * @deti: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(deti_t *deti)
{
	return (isbetty(moka_hadeel) && deti->readfd <= 2);
}

/**
 * is_mark - checks if character is a delimeter
 * @j: the char to check
 * @mark: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_mark(char j, char *mark)
{
	while (*mark)
		if (*mark++ == j)
			return (1);
	return (0);
}

/**
 *_alphabtic - checks for alphabetic character
 *@n: The character to input
 *Return: 1 if n is alphabetic, 0 otherwise
 */

int _alphabtic(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && n <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_shel - converts a string to an integer
 *@m: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _shel(char *m)
{
	int z, line = 1, mar = 0, out;
	unsigned int gain = 0;

	for (z = 0;  s[z] != '\0' && mar != 2; i++)
	{
		if (s[z] == '-')
			line *= -1;

		if (s[z] >= '0' && s[z] <= '9')
		{
			mar = 1;
			gain *= 10;
			gain += (s[i] - '0');
		}
		else if (mar == 1)
			mar = 2;
	}

	if (line == -1)
		out = -gain;
	else
		out = gain;

	return (out);
}
