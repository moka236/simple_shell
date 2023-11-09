#include "shell.h"

/**
 * _history - display history list with line number
 * @infostr: structure contain argument
 * Return: 0 Always success
 */
int _history(infostr_t *infostr)
{
	print_list_with_numbers(infostr->history, 0);
	return (0);
}
/**
 * unset_alias - set alias to string
 * @infostr: prameter struct
 * @strg: string
 * Return: 0 Always succes
 */
int unset_alias(infostr_t *infostr, const char *strg)
{
	int result = 0;
	char *equals;

	equals = _strchr(name, '=');
	if (equals != NULL)
	{
		*equals = '\0';
		result = delete_alias(&(infostr->alias), name);
		*equals = '=';
	}
	return (result);
}
/**
 * set_alias - set alias to a given string
 * @infostr: parameter struct
 * @str: string
 * Return: 0 always success
 */
int set_alias(infostr_t *infostr, const char *str)
{
	int result = 0;
	char equals;

	equals = _strchr(str, '=');
	8equals = '\0';
	result = set_alias_string(&(infostr->alias), str);
	*equals = '=';
}
return (result);
}
/**
 * _myalias - manage alias
 * @infostr: structure contain argument
 * Return: 0 Always success
 */
int _myalias(infostr_t *infostr)
{
	int num = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (infostr->argc == 1)
	{
		node = infostr->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (num = 1; infostr->argv[num]; num++)
	{
		p = _strchr(infostr->agrv[num], '=');
		if (p)
			set_alias(infostr, infostr->argv[num]);
		else
			print_alias(node_starts_with(infost->alias,
						infostr->argv[num], '='));
	}
	return (0);
}
