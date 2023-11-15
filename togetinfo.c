#include "shell.h"
/**
 * initInfo - initilize InfoStruct
 * @infostr:
 * struct address
 * Return: void
 */
void initInfo(InfoStruct *infostr)
{
	infostr->argString = NULL;
	infostr->argumentVector = NULL;
	infostr->executablePath = NULL;
	infostr->argumentCount = 0;
}
/**
 * setInfo - initialize InfoStruct
 * @infostr: struct address
 * @arguments: argument vector
 * Return: void
 */
void setInfo(InfoStruct *infostr, char **arguments)
{
	int i = 0;

	infostr->programName = arguments[0];
	if (infostr->argString)
	{
		infostr->argumentVector = strtow(infostr->argString, " \t");
		if (!infostr->argumentVector)
		{
			infostr->argumentVector = malloc(sizeof(char *) * 2);
			if (infostr->argumentVector)
			{
				infostr->argumentVector[0] = _strdup(infostr->argString);
				infostr->argumentVector[1] = NULL;
			}
		}
	while (infostr->argumentVector && infostr->argumentVector[i])
	{
		i++;
	}
		infostr->argumentCount = i;

		replaceAlias(infostr);
		replaceVariables(infostr);
	}
}
/**
 * freeInfo - free InfoStruct fields
 * @infostr: struct address
 * @all: true if freeing all fields
 * Return: void
 */
void freeInfo(Infostruct *infostr, imt all)
{
	ffree(infost->argumentVector);
	infostr->argumentvector = NULL;
	infostr->executablePath = NULL;

	if (all)
	{
		if (!infostr->commandBuffer)
			free(infostr->argString);

		if (infostr->enviromentVariables)
			freeList(&(infostr->enviromentVariables));
		if (infostr->history)
			freeList(&(infostr->history));
		if (infostr->aliasList)
			freeList(&(infostr->aliasList));

		free(infostr->enviroment);
		infostr->enviroment = NULL;

		free(infostr->commandBuffer);

		if (infostr->readFileDescriptor > 2)
			close(infostr->readFileDescriptor);

		_putchar(BUFFER_FLUSH);
	}
}
