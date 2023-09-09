#include "shell.h"

char *command = NULL;

int main(void)
{

    while (1)
    {
        display_prompt();
        read_command(&command);
        execute_command(command);
    }
    return (0);

}
