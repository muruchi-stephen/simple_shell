#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
       

void display_prompt(void);
void printing_commands(const char *commands);
void execute_command(const char *command);
/*void read_command(char *command, size_t size);*/
void read_command(char **command);


#endif
