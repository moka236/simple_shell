#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

/* Macro for buffer flush */
#define BUF_FLUSH -1

/* Structure for linked list */
typedef struct list_s {
    char *str;
    struct list_s *next;
} list_t;

/* Enumeration for command buffer types */
typedef enum {
    CMD_NORMAL,
    CMD_AND,
    CMD_OR,
    CMD_CHAIN
} CommandBufferType;

/* Structure for parameter information */
typedef struct {
    char *argString;
    char **argumentVector;
    char *executablePath;
    char *programName;
    size_t argumentCount;
    CommandBufferType commandBufferType;
    list_t *aliasList;
    list_t *environmentList;
    int status;
    int historyCount;
    int LineCountFlag;
    int readFileDescriptor;
} InfoStruct;

/* Memory functions */
void *_memset(void *s, int c, size_t n);
void _free(void *ptr);
char *_strdup(const char *s);
size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, size_t n);
char *_strncat(char *dest, const char *src, size_t n);
int _strcmp(const char *s1, const char *s2);

/* Linked list functions */
list_t *addNodeAtStart(list_t **head, const char *str);
list_t *addNodeAtEnd(list_t **head, const char *str);
size_t printListStr(const list_t *head);
int deleteNodeAtIndex(list_t **head, unsigned int index);
void freeList(list_t **head);

/* String manipulation functions */
char *thestrcy(char *dest, const char *src, size_t num);
char *cstrcat(char *dest, const char *src, size_t num);
char *locstrc(char *s, char c);

/* Environment functions */
char **getEnv(InfoStruct *info);
int unsetEnv(InfoStruct *info, char *variable);
int setEnv(InfoStruct *info, char *variable, char *value);
char *mkEnvstr(char *variable, char *value);

/* InfoStruct functions */
void initInfo(InfoStruct *info);
void setInfo(InfoStruct *info, char **arguments);
void freeInfo(InfoStruct *info, int all);

/* Input functions */
ssize_t bufferChainedCommands(InfoStruct *info, char **buffer, size_t *length);
ssize_t getInput(InfoStruct *info);
ssize_t readBuffer(InfoStruct *info, char *buffer, size_t *position);
int customGetline(InfoStruct *info, char **ptr, size_t *length);
void interruptHandler(int sigNum);

/* Command chaining functions */
int isChainDelimiter(InfoStruct *info, char *buffer, size_t *position);
void checkChainContinue(InfoStruct *info, char *buffer, size_t *position, size_t start_position, size_t length);
int replaceAlias(InfoStruct *info);
int replaceVariables(InfoStruct *info);
int replaceString(char **old, char *new);

#endif /* SHELL_H */
