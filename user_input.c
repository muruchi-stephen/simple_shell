#include "shell.h"

void read_command(char *command, size_t size)
{
    if (fgets(command, size, stdin) == NULL)
    {
        if (feof(stdin))
        {
            printing_commands("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            printing_commands("Error while reading input.\n");
            exit(EXIT_FAILURE);
        }
    }
    command[strcspn(command, "\0")] = '\0';
}
