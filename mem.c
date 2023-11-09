#include "shell.h"

/**
 * ffree - frees a pointer and NULLs the address
 * @fr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int ffree(void **fr)
{
	if (fr && *fr)
	{
		free(*fr);
		*fr = NULL;
		return (1);
	}
	return (0);
}
