#include "shell.h"

/**
 * thestrcy - copy string
 * @ds: sting destination
 * @sstr: string ource
 * @num: number of character to be copied
 * Return: string
 */
char *thestrcy(char *ds, const char *sstr, size_t num)
{
	char *t = ds;

	for (size_t u = 0; u < num - 1 && *sstr != '\0'; ++u, ++sstr)
	{
		*ds++ = *sstr;
	}

	for (size_t u = 0; u < num; ++u)
	{
		*ds++ = '\0';
	}
	return (t);
}
/**
 * cstrcat - concatenates two string
 * @ds: string
 * @sstr: string two
 * @num: number of bytes
 * Return: string
 */
char *cstrcat(char *ds, const char *sstr, size_t num)
{
	char *t = ds;

	while (*ds != '\0')
	{
		++ds;
	}

	for (size_t a = 0; a < num && *sstr != '\0'; ++a, ++ds, ++sstr)
	{
		*ds = *sstr;
	}
	if (num > 0)
	{
		*ds = '\0';
	}
	return (t);
}
/**
 * locstrc - locate character in string
 * @r: string
 * @k: character to look for
 * Return: pointer
 */
char *locstrc(char *r, char k)
{
	do {
		if (*r == k)
		{
			return (r);
		}
	}
	while (*r++ != '\0')
	{

	return (NULL);
	}
}
