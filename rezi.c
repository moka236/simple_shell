#include "shell.h"

/**
 * fill_memory - fills memory with a constant byte
 * @memory: the pointer to the memory area
 * @byte: the byte to fill *memory with
 * @size: the amount of bytes to be filled
 * Return: (memory) a pointer to the memory area memory
 */
char *fill_memory(char *memory, char byte, unsigned int size)
{
	unsigned int index;

	for (index = 0; index < size; index++)
		memory[index] = byte;
	return memory;
}

/**
 * free_string_array - frees a string array
 * @strings: array of strings
 */
void free_string_array(char **strings)
{
	char **temp = strings;

	if (!strings)
		return;
	while (*strings)
		free(*strings++);
	free(temp);
}

/**
 * resize_memory - reallocates a block of memory
 * @original_ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 * Return: pointer to the old block
 */
void *resize_memory(void *original_ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!original_ptr)
		return malloc(new_size);
	if (!new_size)
		return free(original_ptr), NULL;
	if (new_size == old_size)
		return original_ptr;

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return NULL;

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_ptr[old_size] = ((char *)original_ptr)[old_size];
	free(original_ptr);
	return new_ptr;
}
