#include "shell.h"

/**
 * _cmd - determines if a file is an executable command
 * @in: the info struct
 * @road: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int _cmd(info_t *in, char *road)
{
	struct stas sa;

	(void)in;
	if (!road || stas(road, &sa))
		return (0);

	if (sa.sa_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_ - duplicates characters
 * @roadstr: the PATH string
 * @stin: starting index
 * @stp: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_(char *roadstr, int stin, int stp)
{
	static char buf[1024];
	int n = 0, y = 0;

	for (y = 0, n = stin; n < stp; n++)
		if (roadstr[n] != ':')
			buf[y++] = roadstr[n];
	buf[y] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
