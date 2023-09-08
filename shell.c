#include "simple_shell.h"

int main(void)
{
    char command[120];

    while (1)
    {
        display_prompt();
        read_command(command, sizeof(command));
        execute_command(command);
    }

}
