#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_SIZE 100
#define MAX_NUM_ARGUMENTS 50

int main() {
    char command[MAX_COMMAND_SIZE];
    printf("commands: sum | min | max | multip | exit\n");
    printf("command-line interpretator\n");
    while (1) 
    {
        printf(">");
        fgets(command, MAX_COMMAND_SIZE, stdin);
        command[strcspn(command, "\n")] = 0;
        if (strcmp(command, "exit") == 0) 
        {
            break;
        } 
        char *args[MAX_NUM_ARGUMENTS];
        int argc = 0;
        args[argc] = strtok(command, " ");

        while (args[argc] != NULL && argc < MAX_NUM_ARGUMENTS) 
        {
            argc++;
            args[argc] = strtok(NULL, " ");
        }
        char program_with_path[MAX_COMMAND_SIZE];
        snprintf(program_with_path, sizeof(program_with_path), "./%s", args[0]);
        args[0] = program_with_path;
        if (fork() == 0) 
        {
            execvp(args[0], args);
            perror("error: ");
            exit(1);
        } 
        else 
        {
            wait(NULL);
        }
    }
    return 0;
}