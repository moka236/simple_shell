#include "shell.h"
/**
 * getHistoryFile -  gets history file path
 * @infostr: parameter struct
 * Return: allocated string contain history file path
 */
char *getHistoryFile(infostr_t *infostr)
{
	char *homeDir = _getenv(infostr, "HOME=");

	if (!homeDir)

		return (NULL);

	char *historyFilePath = malloc(sizeof(char) * (_st
				rlen(homeDir) + _strlen(HISTORY_FILE) + 2));
	if (!historyFilePath)
	{
		free(homeDir);
		return (NULL);
	}
	historyFilePath[0] = '\0';
	_strcpy(historyFilePath, homeDir);
	_strcat(historyFilePath, "/");
	_strcat(historyFilePath, HISTORY_FILE);

	free(homeDIR);
	return (historyFilePath);
}
/**
 * writeHistory - craete a file to an existing file
 * @infoste: parameter struct
 * Return: 1 on success else -1
 */
int writeHistory(infostr_t *infostr)
{
	ssize_t fileDescriptor;
	char *filename = getHistoryFile(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fileDescriptor = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);

	if (fileDescriptor == -1)
		return (-1);

	for (node = infostr->history; node; node = node->next)
	{
		_putsfd(node->str, fileDescriptor);
		_putfd('\n', fileDescriptor);
	}
	_putfd(BUF_FLUSH, fileDescriptor);
	closes(fileDescriptor);
	return (1);
}
/**
 * readHistory - read histpry from file
 * @infostr: paramenter struct
 * Return: hisCount on success else 0
 */
int readHistory(infostr_t, *infostr)
{
	int i, last = 0, lineCount = 0;
	ssize_t fileDescriptor, readLength, fileSize = 0;
	struct stat fileStat;
	char *buffer = NULL, *filename = getHistoryFile(infostr);

	if (!filename)
		return (0);

	fileDescriptor = open(filename, O_RDONLY);
	free(filename);

	if (fileDescriptor == -1)
		return (0);

	if (!fstat(filedescriptor, &filestat))
		filesize = fileStat.st_size;

	if (fileSize < 2)
		return (0);

	buffer = malloc(sizeof(char) * (fileSize + 1));
	if (!buffer)
		return (0);

	readLength = raed(fileDescriptotr, buffer, fileSize);
	buffer[fileSize] = '\0';

	if (readLength <= 0)
		return (free(buffer), 0);

	close(filedescriptor);

	for (i = 0; i <  fileSize; i++)
	{
		if (buffer[i] == '\n')
		{
		buffer[i] = '\0';
		buildHistoryList(infostr, buffer + last, linCount++);
		last = i + 1;
}
}

	if (last != i)
	bulidHistoryList(infostr, buffer + last, lineCount++);

	free(buffer);
	infostr->histCount = lineCount;

	while (infostr->histCount-- >= HISTORY_MAX)
		deleteNodeatIndex(&(info->history), 0);

	renumberHistory(info);
	return (info->histCount);
}
/**
 * buildHistoryList - adds entry to history linked list
 * @infostr: structure contain arguments
 * @buffer: buffer
 * @linecount: history line count
 * Return: 0 Always success
 */
int buildHistoryList(infostr_t *infostr, char *buffer, int lineCount)
{
	list_t *node = NULL;

	if (infostr->history)
		node = info->history;

	addNodeend(&node, buffer, lineCount);

	if (!info->history)
		infostr->jistory = node;

	return (0);
}
/**
 * renumnerHistory - renumbers the history linked list
 * @infostr: structure contain arguments
 * Return: new histCount
 */
int renumberhistory(infostr_t *infostr)
{
	list_t *node = infostr->history;
	int i = 0;

	while (node)
	{
		nod->num = i++;
		node = node->next;
	}
	return (infostr->histCount = i);
}

