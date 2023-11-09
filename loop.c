#include "shell.h"

/**
 * shellMainLoop - main shell loop
 * @shellInfo: the parameter & return shell information struct
 * @arguments: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int shellMainLoop(shell_info_t *shellInfo, char **arguments)
{
	ssize_t readResult = 0;
	int builtinResult = 0;

	while (readResult != -1 && builtinResult != -2)
	{
		clearShellInfo(shellInfo);
		if (isInteractiveMode(shellInfo))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		readResult = getInputFromUser(shellInfo);
		if (readResult != -1)
		{
			setShellInfo(shellInfo, arguments);
			builtinResult = findBuiltinCommand(shellInfo);
			if (builtinResult == -1)
				findCommandInPath(shellInfo);
		}
		else if (isInteractiveMode(shellInfo))
			_putchar('\n');
		freeShellInfo(shellInfo, 0);
	}
	writeHistory(shellInfo);
	freeShellInfo(shellInfo, 1);
	if (!isInteractiveMode(shellInfo) && shellInfo->status)
		exit(shellInfo->status);
	if (builtinResult == -2)
	{
		if (shellInfo->errorNumber == -1)
			exit(shellInfo->status);
		exit(shellInfo->errorNumber);
	}
	return (builtinResult);
}

/**
 * findBuiltinCommand - finds a builtin command
 * @shellInfo: the parameter & return shell information struct
 *
 * Return: -1 if builtin not found,
 *         0 if builtin executed successfully,
 *         1 if builtin found but not successful,
 *         -2 if builtin signals exit()
 */
int findBuiltinCommand(shell_info_t *shellInfo)
{
	int index, builtinResult = -1;
	builtin_table_t builtinTable[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (index = 0; builtinTable[index].command; index++)
		if (_strcmp(shellInfo->arguments[0], builtinTable[index].command) == 0)
		{
			shellInfo->lineCount++;
			builtinResult = builtinTable[index].function(shellInfo);
			break;
		}
	return (builtinResult);
}

/**
 * findCommandInPath - finds a command in PATH
 * @shellInfo: the parameter & return shell information struct
 *
 * Return: void
 */
void findCommandInPath(shell_info_t *shellInfo)
{
	char *path = NULL;
	int index, argCount;

	shellInfo->path = shellInfo->arguments[0];
	if (shellInfo->lineCountFlag == 1)
	{
		shellInfo->lineCount++;
		shellInfo->lineCountFlag = 0;
	}
	for (index = 0, argCount = 0; shellInfo->arguments[index]; index++)
		if (!isDelimiter(shellInfo->arguments[index], " \t\n"))
			argCount++;
	if (!argCount)
		return;

	path = findCommandPath(shellInfo, _getenv(shellInfo, "PATH="), shellInfo->arguments[0]);
	if (path)
	{
		shellInfo->path = path;
		forkExecuteCommand(shellInfo);
	}
	else
	{
		if ((isInteractiveMode(shellInfo) || _getenv(shellInfo, "PATH=")
			 || shellInfo->arguments[0][0] == '/') && isCommand(shellInfo, shellInfo->arguments[0]))
			forkExecuteCommand(shellInfo);
		else if (*(shellInfo->arguments) != '\n')
		{
			shellInfo->status = 127;
			printError(shellInfo, "not found\n");
		}
	}
}

/**
 * forkExecuteCommand - forks an execution thread to run command
 * @shellInfo: the parameter & return shell information struct
 *
 * Return: void
 */
void forkExecuteCommand(shell_info_t *shellInfo)
{
	pid_t childPid;

	childPid = fork();
	if (childPid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (childPid == 0)
	{
		if (execve(shellInfo->path, shellInfo->arguments, getEnvironment(shellInfo)) == -1)
		{
			freeShellInfo(shellInfo, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(shellInfo->status));
		if (WIFEXITED(shellInfo->status))
		{
			shellInfo->status = WEXITSTATUS(shellInfo->status);
			if (shellInfo->status == 126)
				printError(shellInfo, "Permission denied\n");
		}
	}
}
