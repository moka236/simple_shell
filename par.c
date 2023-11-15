#include "shell.h"

/**
 * is_executable_command - determines if a file is an executable command
 * @information: the information struct
 * @file_path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_executable_command(info_t *information, char *file_path)
{
    struct stat file_stat;

    (void)information;
    if (!file_path || stat(file_path, &file_stat))
        return 0;

    if (file_stat.st_mode & S_IFREG && file_stat.st_mode & S_IXUSR)
    {
        return 1;
    }
    return 0;
}

/**
 * duplicate_characters - duplicates characters
 * @source_string: the source string
 * @start_index: starting index
 * @stop_index: stopping index
 *
 * Return: dynamically allocated string with duplicated characters
 */
char *duplicate_characters(const char *source_string, int start_index, int stop_index)
{
    char *buffer = NULL;
    int k = 0;

    if (!source_string || start_index < 0 || stop_index < start_index)
        return NULL;

    buffer = malloc((stop_index - start_index + 1) * sizeof(char));
    if (!buffer)
        return NULL;

    for (int i = start_index; i < stop_index; i++)
    {
        if (source_string[i] != ':')
        {
            buffer[k++] = source_string[i];
        }
    }
    buffer[k] = '\0';
    return buffer;
}

/**
 * find_command_path - finds the command in the PATH string
 * @information: the information struct
 * @path_string: the PATH string
 * @command: the command to find
 *
 * Return: dynamically allocated string with the full path of command if found, or NULL
 */
char *find_command_path(info_t *information, const char *path_string, const char *command)
{
    int i = 0, current_position = 0;
    char *path = NULL;

    if (!path_string || !command)
        return NULL;

    if ((_strlen(command) > 2) && starts_with(command, "./"))
    {
        if (is_executable_command(information, command))
            return strdup(command);
    }

    while (1)
    {
        if (!path_string[i] || path_string[i] == ':')
        {
            path = duplicate_characters(path_string, current_position, i);
            if (!*path)
                _strcat(path, command);
            else
            {
                _strcat(path, "/");
                _strcat(path, command);
            }
            if (is_executable_command(information, path))
                return path;
            free(path);
            path = NULL;

            if (!path_string[i])
                break;

            current_position = i;
        }
        i++;
    }
    return NULL;
}
