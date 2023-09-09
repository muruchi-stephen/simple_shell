#include "shell.h"

void printing_commands(const char *commands)
{
    write(1, commands, strlen(commands));
}
