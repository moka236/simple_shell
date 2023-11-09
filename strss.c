#include "shell.h"

/**
 * copyString - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *copyString(char *dest, char *src)
{
	int index = 0;

	if (dest == src || src == NULL)
		return (dest);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	return (dest);
}

/**
 * duplicateString - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *duplicateString(const char *str)
{
	int length = 0;
	char *result;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	result = malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	for (length++; length--;)
		result[length] = *--str;
	return (result);
}

/**
 * displayString - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void displayString(char *str)
{
	int index = 0;

	if (!str)
		return;
	while (str[index] != '\0')
	{
		outputCharacter(str[index]);
		index++;
	}
}

/**
 * outputCharacter - writes the character c to stdout
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int outputCharacter(char ch)
{
	static int currentIndex;
	static char buffer[WRITE_BUFFER_SIZE];

	if (ch == BUFFER_FLUSH || currentIndex >= WRITE_BUFFER_SIZE)
	{
		write(1, buffer, currentIndex);
		currentIndex = 0;
	}
	if (ch != BUFFER_FLUSH)
		buffer[currentIndex++] = ch;
	return (1);
}
