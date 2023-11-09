#include "shell.h"

/**
 * entry_point - main function
 * @argument_count: argument count
 * @argument_vector: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int entry_point(int argument_count, char **argument_vector)
{
    info_t information[] = { INFO_INIT };
    int file_descriptor = 2;

    asm ("mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (file_descriptor)
        : "r" (file_descriptor));

    if (argument_count == 2)
    {
        file_descriptor = open(argument_vector[1], O_RDONLY);
        if (file_descriptor == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _error_puts(argument_vector[0]);
                _error_puts(": 0: Can't open ");
                _error_puts(argument_vector[1]);
                _error_putchar('\n');
                _error_putchar(BUF_FLUSH);
                exit(127);
            }
            return EXIT_FAILURE;
        }
        information->read_file_descriptor = file_descriptor;
    }
    populate_environment_info(information);
    read_shell_command_history(information);
    run_shell(information, argument_vector);
    return EXIT_SUCCESS;
}
