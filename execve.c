#include "shell.h"

void execute_command(const char *command)
{
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        execlp(command, command, (char *)NULL);
        perror("execlp");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}


/*void execute_command(const char* path, const char* argv[], char* const envp[])
{
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        execve();
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}*/
