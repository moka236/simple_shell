#include "shell.h"

/**
 * add_list_node_start - adds a node to the start of the list
 * @list_head: address of pointer to head node
 * @str_value: str field of node
 * @node_index: node index used by history
 *
 * Return: size of list
 */
list_t *add_list_node_start(list_t **list_head, const char *str_value, int node_index)
{
	list_t *new_list_head;

	if (!list_head)
		return (NULL);
	new_list_head = malloc(sizeof(list_t));
	if (!new_list_head)
		return (NULL);
	_memset((void *)new_list_head, 0, sizeof(list_t));
	new_list_head->node_index = node_index;
	if (str_value)
	{
		new_list_head->str_value = _strdup(str_value);
		if (!new_list_head->str_value)
		{
			free(new_list_head);
			return (NULL);
		}
	}
	new_list_head->next = *list_head;
	*list_head = new_list_head;
	return (new_list_head);
}

/**
 * add_list_node_end - adds a node to the end of the list
 * @list_head: address of pointer to head node
 * @str_value: str field of node
 * @node_index: node index used by history
 *
 * Return: size of list
 */
list_t *add_list_node_end(list_t **list_head, const char *str_value, int node_index)
{
	list_t *new_node, *current_node;

	if (!list_head)
		return (NULL);

	current_node = *list_head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->node_index = node_index;
	if (str_value)
	{
		new_node->str_value = _strdup(str_value);
		if (!new_node->str_value)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (current_node)
	{
		while (current_node->next)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	else
		*list_head = new_node;
	return (new_node);
}

/**
 * print_list_strings - prints only the str_value element of a list_t linked list
 * @list_ptr: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_strings(const list_t *list_ptr)
{
	size_t size = 0;

	while (list_ptr)
	{
		_puts(list_ptr->str_value ? list_ptr->str_value : "(nil)");
		_puts("\n");
		list_ptr = list_ptr->next;
		size++;
	}
	return (size);
}

/**
 * delete_node_at_index - deletes node at given index
 * @list_head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **list_head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!list_head || !*list_head)
		return (0);

	if (!index)
	{
		node = *list_head;
		*list_head = (*list_head)->next;
		free(node->str_value);
		free(node);
		return (1);
	}
	node = *list_head;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str_value);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list_nodes - frees all nodes of a list
 * @list_head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list_nodes(list_t **list_head_ptr)
{
	list_t *node, *next_node, *head;

	if (!list_head_ptr || !*list_head_ptr)
		return;
	head = *list_head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str_value);
		free(node);
		node = next_node;
	}
	*list_head_ptr = NULL;
}
