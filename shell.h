#ifndef SHELL_H
#define SHELL_H

/*
 * shell.h - Header file for a simple shell program
 * Author: Mohamed Emad - Hadeel ahmed 
 * Date: November 30, 2023
 */

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define BUFFER_FLUSH '\0'
#define WRITE_BUFFER_SIZE 1024
#define READ_BUFFER_SIZE 1024
#define USE_GETLINE 1

/**
 * struct list_s - singly linked list
 * @str: string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

/**
 * struct InfoStruct - structure to hold shell information
 * @argString: argument string
 * @argumentVector: array of arguments
 * @executablePath: path of the executable
 * @argumentCount: number of arguments
 * @programName: name of the program
 * @commandBuffer: buffer for command input
 * @LineCountFlag: flag for line count
 * @historyCount: count of command history
 * @status: command execution status
 * @command_buffer_type: type of command buffer
 * @environmentVariables: environment variable list
 * @history: command history list
 * @aliasList: alias list
 * @environment: environment list
 * @environ: environment array
 * @envChanged: flag indicating environment change
 * @readFileDescriptor: file descriptor for reading
 */
typedef struct InfoStruct {
    char *argString;
    char **argumentVector;
    char *executablePath;
    int argumentCount;
    char *programName;
    char *commandBuffer;
    int LineCountFlag;
    int historyCount;
    int status;
    int command_buffer_type;
    list_t *environmentVariables;
    list_t *history;
    list_t *aliasList;
    list_t *environment;
    list_t *environ;
    int envChanged;
    int readFileDescriptor;
} InfoStruct;

/**
 * struct info_t - structure to hold shell information
 * @alias_list: alias list
 * @environment_list: environment list
 * @arguments: array of arguments
 * @status: command execution status
 * @command_buffer_type: type of command buffer
 */
typedef struct info_t {
    list_t *alias_list;
    list_t *environment_list;
    char **arguments;
    int status;
    int command_buffer_type;
} info_t;

/* Function prototypes */

int calculateLength(char *str);
int compareStrings(char *string1, char *string2);
char *startsWithSubstring(const char *haystack, const char *needle);
char *concatenateStrings(char *destination, char *source);

char *copyString(char *dest, char *src);
char *duplicateString(const char *str);
void displayString(char *str);
int outputCharacter(char ch);

void initInfo(InfoStruct *infostr);
void setInfo(InfoStruct *infostr, char **arguments);
void freeInfo(InfoStruct *infostr, int all);
ssize_t bufferChainedCommands(infostr_t *infostr, char **buffer, size_t *length);
ssize_t getInput(infostr_t *infostr);
ssize_t readBuffer(infostr_t *infostr, char *buffer, size_t *position);
int customGetline(infostr_t *infostr, char **ptr, size_t *length);
void interruptHandler(int sigNum);

int is_chain_delimiter(info_t *info, char *buffer, size_t *position);
void check_chain_continue(info_t *info, char *buffer, size_t *position, size_t start_position, size_t length);
int replace_alias(info_t *info);
int replace_variables(info_t *info);
int replace_string(char **old, char *new);

#endif /* SHELL_H */
