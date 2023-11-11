#include "shell.h"
/**
 * addNodeAtStart - add a node to the start of the list
 * @head: address of pointer
 * @str: str field of node
 * @num: node index
 * Return: pointer to th enew head
 */
list_t *addNodeAtStart(list_t **head, const char *str, int num)
{
	list_t *newHead;

	if (!head)
		return (NULL);

	newHead = malloc(sizeof(list_t));
	if (!newHead)
		return (NULL);
	_memset((void *)newHead, 0, sizeof(list_t));
	newHead->num = num;

	if (str)
	{
		newHead->str = _strdup(str);
		if (!newHead->str)
		{
			free(newHead);
			return (NULL);
		}
	}
	newHead->next = *head;
	*head = newHead;
	return (newHead);
}
/**
 * addNodeAtEnd - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: field of node
 * @num: node index
 * Return: pointer to the new node
 */
list_t *addNodeAtEnd(list_t **head, const char *str, int num)
{
	list_t *newNode, *node;

	if (!head)
		return (NULL);

	node = *head;
	newNode = malloc(sizeof(list_t));
	if (!newNode)
		return (NULL);

	_memset((void *)newNode, 0, sizeof(list_t));
	newNode->num = num;

	if (str)
	{
		newNode->str = _strdup(str);
		if (!newNode->str)
		{
			free(newNode);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = newNode;
	}
	else
	{
		*head = newNode;
	}
	return (newNode);
}
/**
 * printListStr - prints only
 * @head:pointeer to first node
 * Return: size of list
 */
size_t printListStr(const list_t *head)
{
	size_t size = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		size++;
	}
	return (size);
}
/**
 * deleteNodeAtIndex - delete node at given index
 * @head: address of pointer
 * @index: index of node
 * Return: 1 always success else 0
 */
int deleteNodeAtIndex(list_t **head, unsigned int index)
{
	list_t *node, *prevNode;
	unsigned int i = 0;

	if (!head || *head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}

	node = *head;

	while (node)
	{
		if (i == index)
		{
			prevNode->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		revNode = node;
		node = node->next;
	}
	return (0);
}
/**
 * freeList - free all node of list
 * @headPtr: address of pointer to head node
 * Return: void
 */
void freeList(list_t **headPtr)
{
	list_t *node, *nextNode, *head;

	if (!headPtr || !*headPtr)
		return;

	head = *headPtr;
	node = head;

	while (node)
	{
		nextNode = node->next;
		free(node->str);
		free(node);
		node = nextNode;
	}
	*headPtr = Null;
}
