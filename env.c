#include "shell.h"
/**
 * prenv - prints the current inviroment
 * @infostr: structure contain potential arguments
 * Return: 0 always success
 */
int prenv(infostr_t *infostr)
{
	print_list_str(infotr->env);
	return (0);
}

/**
 * getEnv - get the value of a varaiable
 * @infostr: structure contain arguments
 * @envname: enviroment name
 * Return: value
 */
char *getEnv(infostr_t *infostr, const char *envname)
{
	list_t *node = infostr->env;
	char *a;

	while (node)
	{
		a = starts_with(node->str, envname)
			if (a && *a)
				return (a);
		node = node->next;
	}
	return (NULL);
}

/**
 * setEnv - initilaize a new variable
 * @infostr: structure contain variable
 * Return: 0 always success
 */
int setEnv(infostr_t *infostr)
{
	if (infostr->argc < 3)
	{
	_eputs("Usage: setenv VARIABLE VALUE\n");
	return (1);
}
if (_setenv(infostr, infostr->argv[1], infostr->argv[2]))
	return (0);

	return (1);
	}
/**
 * remEnv - remove an enviroment variable
 * @infostr: structure contain arguments
 * Return: 0 always success
 */
int remEnv(infostr_t *infostr)
{
	int e;

	if (infostr->argc < 2)
	{
		_eputs("Usage: remenv VARIABLE [VARIABLE...]\n");
		return (1);
	}
	for (e = 1; e < infostr->argc; e++)
		_unsetenv(infostr, infostr->argv[e]);
	return (0);
}

/**
 * popEnvlist - populates env linked list
 * @infostr: structure contain argumets
 * Return: 0 always success
 */
int popEnvlist(infostr_t *infostr)
{
	list_t *node = NULL;
	size_t e;

	for (e = 0; environ[e]; e++)
		add_node_end(&node, environ[e], 0);
	infostr->env = node;
	return (0);
}
