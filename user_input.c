#include "shell.h"

/*void read_command(char *command, size_t size)
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
}*/

/*void read_command(char **command)
{
    size_t len = 0;
    if (getline(command, &len, stdin) == -1)
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
    (*command)[strcspn(*command, "\n")] = '\0';  
}*/

void read_command(char **command)
{
    size_t len = 0;
    ssize_t read;

    read = getline(command, &len, stdin);
    if (read == -1)
    {
        if (!isatty(STDIN_FILENO))
        {
            printing_commands("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            /*printing_commands("Error while reading input.\n");*/
            printing_commands("\n");
            exit(EXIT_FAILURE);
        }
    }
    (*command)[strcspn(*command, "\n")] = '\0'; /*remove newline character*/ 
}
