#include "shell.h"

/**
 * bufferChainedCommands - buffers chained commands
 * @infostr: parameter struct
 * @buffer: address of buffer
 * @length: address of length var
 * Return: bytes
 */
ssize_t bufferChainedCommands(infostr_t *infostr
		, char **buffer, size_t *length)
{
	ssize_t bytesRead = 0;
	size_t currentLength = 0;

	if (!*length)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, interruptHandler);

#if USE_GETLINE
		bytesRead = getline(buffer, &currentLength, stdin);
#else
		bytesRead = customGetline(infostr, buffer, &currentLength);
#endif
		if (bytesRead > 0)
		{
			if ((*buffer)[bytesRead - 1] == '\n')
			{
				(*buffer)[bytesRead - 1] = '\0';
				bytesRead--;
			}

			infostr->LineCountFlag = 1;
			removeComments(*buffer);
			buildHistoryList(infostr, *buffer, infostr->historyCount++);
			if (_strchr(*buffer, ';'))
			{
				*length = bytesRead;
				infostr->commandBuffer = buffer;
			}
		}
	}
	return (bytesRead);
}

/**
 * getInput - get a line minus the newline
 * @infostr: parameter struct
 * Return:bytes read
 */
ssize_t getInput(infostr_t *infostr)
{
	static char *commandBuffer;
	static size_t currentPos, nextPos, bufferLength;
	ssize_t bytesRead = 0;
	char **commandPtr = &(infostr->arguments), *currentPtr;

	_putchar(BUFFER_FLUSH);
	bytesRead = bufferChainedCommands(infostr, &commandBuffer, &bufferLength);

	if (bytesRead == -1)
		return (-1);

	if (bufferLength)
	{
		nextPos = currentPos;
		currentPtr = commandBuffer + currentPos;

		checkCommandChain(infostr, commsndBuffer, &n
				extPos, currentpos, bufferlength);
		while (nextPos < bufferLength)
		{
			if (isCommandChain(infostr, commandBuffer, &nextPos))
				break;
			nextPos++;
		}

		currentPos = nextPos + 1;
		if (currentPos >= bufferLength)
		{
			currentPos = bufferLength = 0;
			infostr->commandBufferType = CMD_NORMAL;
		}
		*commandPtr = currentPtr;
		return (_strlen(currentPtr));
	}

	*commandPtr = commandBuffer;
	return (bytesRead);
}
/**
 * readBuffer - read a buffer
 * @infostr: parameter struct
 * @buffer: buffer
 * @position: size
 * Return: bytes read
 */
ssize_t readBuffer(infostr_t *infostr, char *buffer, size_t *position)
{
	ssize_t bytesRead = 0;

	if (*position)
		return (0);

	bytesRead = read(infostr->readFd, buffer, READ_BUFFER_SIZE);

	if (bytesRead >= 0)
		*position = bytesRead;

	return (bytesRead);
}
/**
 * customGetline - get the next line
 * @infostr: parameter struct
 * @ptr:
 * address pf pointer to buffer
 * @length: size pf preallocated
 * Return: size
 */
int customGetline(infostr_t *infostr, char **ptr, size_t *length)
{
	static char buffer[READ_BUFFER_SIZE];
	static size_t currentPos, bufferLength;
	size_t index;
	ssize_t bytesRead = 0, size = 0;
	char *currentPtr = NULL, *newptr = NULL, *ch;

	currentPtr = *ptr;
	if (currentPtr && length)
		size = *length;

	if (currentPos == bufferLength)
		currentPos = bufferLength = 0;
	bytesRead = readBuffer(infostr, buffer, &bufferLength);
	if (bytesRead == -1 || (bytesRead == 0 && bufferLength == 0))
		return (-1);

	ch = strchr(buffer + currentPos, '\n');
	index = ch ? 1 + (unsigned int)(ch - buffer) : bufferLength;
	newPtr = _realloc(currentPtr, size, size ? size + index : index + 1);
	if (!newPtr)
		return (currentPtr ? free(currentPtr), -1 : -1);

	if (size)
		_strncat(newPtr, buffer + currentPos, index - currentPos);
	else
		_strncpy(newPtr, buffer + currentPos, index - currentPos + 1);
	size += index - currentPos;
	currentPos = index;
	currentPtr = newPtr;

	if (length)
		*length = size;
	*ptr = currentPtr;
	return (size);
}
/**
 * interruptHandler - blocks ctrl-C
 * @sigNum: the signal number
 * Return: void
 */
void interruptHandler(__attribute__((unused)) int sigNum)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUFFER_FLUSH);
}
