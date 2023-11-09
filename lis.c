#include "shell.h"

/**
 * _len - determines length of linked list
 * @k: pointer to first node
 *
 * Return: size of list
 */
size_t _len(const list_t *k)
{
	size_t n = 0;

	while (k)
	{
		k = k->next;
		n++;
	}
	return (n);
}

/**
 * _strings - returns an array of strings of the list->str
 * @fir: pointer to first node
 *
 * Return: array of strings
 */
char **_strings(list_t *fir)
{
	list_t *node = fir;
	size_t n = _len(fir), b;
	char **sur;
	char *suur;

	if (!fir || !n)
		return (NULL);
	strs = malloc(sizeof(char *) * (n + 1));
	if (!sur)
		return (NULL);
	for (n = 0; nod; nod = nod->next, n++)
	{
		suur = malloc(_strlen(nod->suur) + 1);
		if (!sur)
		{
			for (b = 0; b < n; b++)
				free(suur[b]);
			free(suur);
			return (NULL);
		}

		suur = _strcpy(suur, nod->suur);
		sur[n] = sur;
	}
	suur[n] = NULL;
	return (suur);
}


/**
 * print_ - prints all elements of a list_t linked list
 * @m: pointer to first node
 *
 * Return: size of list
 */
size_t print_(const list_t *m)
{
	size_t n = 0;

	while (m)
	{
		_puts(convert_number(m->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->sur ? m->sur : "(nil)");
		_puts("\n");
		m = m->next;
		n++;
	}
	return (n);
}

/**
 * starts_wi - returns node whose string starts with prefix
 * @nod: pointer to list head
 * @pre: string to match
 * @u: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *starts_wi(list_t *nod, char *pre, char u)
{
	char *r = NULL;

	while (nod)
	{
		r = starts_wi(nod->sur, pre);
		if (r && ((u == -1) || (*r == u)))
			return (nod);
		nod = nod->next;
	}
	return (NULL);
}

/**
 * _index - gets the index of a node
 * @fh: pointer to list head
 * @nod1: pointer to the node
 *
 * Return: index of nod1 or -1
 */
ssize_t _index(list_t *fh, list_t *nod1)
{
	size_t n = 0;

	while (fh)
	{
		if (fh == nod1)
			return (n);
		fh = fh->next;
		fh++;
	}
	return (-1);
}
