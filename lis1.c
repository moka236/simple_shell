#include "shell.h"

/**
 * list_length - determines length of linked list
 * @list_ptr: pointer to first node
 *
 * Return: size of list
 */
size_t list_length(const list_t *list_ptr)
{
	size_t count = 0;

	while (list_ptr)
	{
		list_ptr = list_ptr->next;
		count++;
	}
	return count;
}

/**
 * list_to_array - returns an array of strings of the list->str
 * @list_head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_array(list_t *list_head)
{
	list_t *current_node = list_head;
	size_t size = list_length(list_head), index;
	char **strings;
	char *str_value;

	if (!list_head || !size)
		return NULL;
	strings = malloc(sizeof(char *) * (size + 1));
	if (!strings)
		return NULL;
	for (index = 0; current_node; current_node = current_node->next, index++)
	{
		str_value = malloc(_strlen(current_node->str) + 1);
		if (!str_value)
		{
			for (size_t j = 0; j < index; j++)
				free(strings[j]);
			free(strings);
			return NULL;
		}

		str_value = _strcpy(str_value, current_node->str);
		strings[index] = str_value;
	}
	strings[index] = NULL;
	return strings;
}

/**
 * print_linked_list - prints all elements of a list_t linked list
 * @list_ptr: pointer to first node
 *
 * Return: size of list
 */
size_t print_linked_list(const list_t *list_ptr)
{
	size_t count = 0;

	while (list_ptr)
	{
		_puts(convert_number(list_ptr->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(list_ptr->str ? list_ptr->str : "(nil)");
		_puts("\n");
		list_ptr = list_ptr->next;
		count++;
	}
	return count;
}

/**
 * find_node_with_prefix - returns node whose string starts with prefix
 * @list_head: pointer to list head
 * @match_prefix: string to match
 * @next_char: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *find_node_with_prefix(list_t *list_head, char *match_prefix, char next_char)
{
	char *match = NULL;

	while (list_head)
	{
		match = starts_with(list_head->str, match_prefix);
		if (match && ((next_char == -1) || (*match == next_char)))
			return list_head;
		list_head = list_head->next;
	}
	return NULL;
}

/**
 * get_node_index_in_list - gets the index of a node
 * @list_head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index_in_list(list_t *list_head, list_t *node)
{
	size_t index = 0;

	while (list_head)
	{
		if (list_head == node)
			return index;
		list_head = list_head->next;
		index++;
	}
	return -1;
}
