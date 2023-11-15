#include "shell.h"

/**
 * getEnv - retuen string array of enciron
 * @infostr: strructure contain arguments
 * Return: string array
 */
char **getEnv(infostr_t *infostr)
{
	if (!infostr->environ || infostr->envChanged)
	{
		infostr->environ = listToStrings(infostr->env);
		infostr->envChanged = 0;
	}
	return (infostr->environ);
}
/**
 * unSetenv - remove envirmonent variable
 * @infostr: structure contain arguments
 * @varble: variable
 * Return: 1 on success else 0
 */
int unSetenv(infostr_t *infostr, char *varble)
{
	if (!infostr->env || !varble)
		return (-1);

	size_t t = 0;
	list_t *node = infostr->env;

	while (node)
	{
		char *r = startsWithSubstring(node->str, varble);

		if (r && *r == '=')
		{
			infostr->envChanged = deleteNodeAtIndex(&(infostr->env), t);
			return (infostr->envChanged);
		}
		node = node->next;
		t++;
	}
	return (-1);
}
/**
 * setEnvro - initlize a new enviroment
 * @infostr: structure contain argumnent
 * @varble: enviroment variable
 * @v: enviroment value
 * Return: 0 always success else 1
 */
int setEnvro(infostr_t *infostr, char *varble, char *v)
{
	if (!var || !value)
		return (1);

	char *buf = mkEnvstr(v, value);

	if (!buf)
		return (1);

	list_t *node = infostr->env;

	while (node)
	{
		char *r = startsWithiSubstring(node->str, v);

		if (r && *r == '=')
		{
			free(node->str);
			node->str = buf;
			infostr->envChanged = 1;

			return (0);
		}
		node = node->next;
	}
	addNodeEnd(&(infostr->env), buf, 0);
	free(buf);
	infostr->envChanged = 1;
	return (0);
}
/**
 * mkEnvstr - make string
 * @varble: string enviroment
 * @v: enviroment variable
 * Return: maked string
 */
char *mkEnvstr(char *varble, char *v)
{
	char *buf = malloc(_strlen(varble) + _strlen(v) + 2);

	if (!buf)
		return (NULL);

			_strcpy(buf, varble);
	_strcat(buf, "=");
	_strcat(buf, v);

	return (buf);
}
