#include "shell.h"

/**
 * main - entry point
 * @ar: arg count
 * @ag: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ar, char **ag)
{
	info_t fo[] = { FO_INIT };
	int fe = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fe)
		: "r" (fe));

	if (ar == 2)
	{
		fe = open(ag[1], O_RDONLY);
		if (fe == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(ag[0]);
				_eputs(": 0: Can't open ");
				_eputs(ag[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		fo->readfe= fe;
	}
	populate_env_list(fo);
	read_history(fo);
	hsh(fo, ag);
	return (EXIT_SUCCESS);
}
