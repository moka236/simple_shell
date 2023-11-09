#include "shell.h"

/**
 * calculateLength - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */
int calculateLength(char *str)
{
	int length = 0;

	if (!str)
		return (0);

	while (*str++)
		length++;
	return (length);
}

/**
 * compareStrings - performs lexicographic comparison of two strings.
 * @string1: the first string
 * @string2: the second string
 *
 * Return: negative if string1 < string2, positive if string1 > string2, zero if string1 == string2
 */
int compareStrings(char *string1, char *string2)
{
	while (*string1 && *string2)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
	}
	if (*string1 == *string2)
		return (0);
	else
		return (*string1 < *string2 ? -1 : 1);
}

/**
 * startsWithSubstring - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of the next character of haystack or NULL
 */
char *startsWithSubstring(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * concatenateStrings - concatenates two strings
 * @destination: the destination buffer
 * @source: the source buffer
 *
 * Return: pointer to the destination buffer
 */
char *concatenateStrings(char *destination, char *source)
{
	char *result = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (result);
}
