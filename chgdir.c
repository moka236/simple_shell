#include "shell.h"

/**
 * _theexit - exit the shell
 * @infostr: structure containing potential argument
 * Return: 0 for success else 1
 */
int _theexit(infostr_t *infostr)
{
	if (infostr->argv[1])
	{
		int exitcode = _erratoi(infostr->argv[1]);

		if (exitcode == -1)
		{
			infostr->status = 2;
			print_error(infostr, "ILLegal number: ");
			_eputs(infostr->argv[1]);
			_eputchar('\n');
			return (1);
		}
		infostr->err_num = exutcode;
	}
	else
	{
		info->err_num = -1;
	}
	return (0);
}

/**
 * _cd - change current directory
 * @infostr: structure contain argument
 * Return: 0 if success else 1
 */

int _cd(infostr_t *infostr)
{
	char *dir, buffer[1024];
	int chgdir;

	char *currentDir = getcwd(buffer, 1024);

	if (!currentDir)
	{
	_puts("Error: getcwd faild.\n");
	return (1);
	}
	if (!infostr->argv[1])
	{
	dir = _getenv(infostr, "HOME=");
	if (!dir)
	{
	dir = _getenv(infostr, "PWD=");
	if (!dir)
	{
	dir = "/";
	}
	}
	}
	else if (_strcmp(infostr->argv[1], "_") == 0)
	{
	dir = _getenv(infostr, "OLDPWD=");
	if (!dir)
	{
	_puts(currentDir);
	_putchar('\n');
	return (0);
	}
	}
	else
	{
	dir = infostr->argv[1];
	}
	chgdir = chgdir(dir);

	if (chgdir == -1)
	{
	print_error(infostr, "can't cd to ");
	_eputs(infostr->argv[1]);
	_eputchar('\n');
	return (1);
	}
	else
	{
		_setenv(infostr, "OLDPWD", _getenv(infostr, "PWD="));
		_setenv(infostr, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _help - display help message
 * @infostr: structure contain argument
 * Return: 0 Always success
 */
int _help(infostr_t *infostr)
{
	_puts("Help function not yet implemented.\n");
	return (0);
}
