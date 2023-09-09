/* #include "shell.h"

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
        char command_buffer[1024];  Create a buffer to store the command
        strcpy(command_buffer, command);  Copy the command to the buffer

        char *args[] = {command_buffer, NULL};
        char *envp[] = {NULL};

        execve(command_buffer, args, envp);
        execlp(command, command, (char *)NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        wait(NULL);
    }
}*/


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

/*#include "shell.h"

void execute_command(const char *command)
{
    pid_t child_pid;

    if (strcmp(command, "/bin/ls") == 0)
    {
        char *argv[] = {"/bin/ls", NULL};
        child_pid = fork();

        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            execve(argv[0], argv, NULL);
            perror("execve");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }
    }
    else
    {
        printing_commands("Command not supported. Use \"/bin/ls\"\n");
    }
}*/

#include "shell.h"

/*void execute_command(const char *command)
{
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == -1)
    {
        printing_commands("Error forking process.\n");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        char *args[128];
        int arg_count = 0;

        char *token = strtok((char *)command, " ");
        while (token != NULL)
        {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;
        execvp(args[0],args);
        printing_commands("Error executing commands.\n");
        exit(EXIT_FAILURE);
    }
    else 
    {
        wait(NULL);
    }
}*/

void execute_command(const char *command)
{
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == -1)
    {
        printing_commands("Error forking process.\n");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        char *args[128];
        int arg_count = 0;

        char *token = strtok((char *)command, " ");
        while (token != NULL)
        {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        if (access(args[0], F_OK) != 0) /*Check if the file exists*/
        {
            perror(args[0]); /*Print the error message*/ 
            exit(EXIT_FAILURE);
        }

        execve(args[0], args, NULL);
        perror(args[0]); /*Print the error message if execve fails*/ 
        exit(EXIT_FAILURE);
    }
    else 
    {
        wait(NULL);
    }
}
