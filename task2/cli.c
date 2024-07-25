#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 100
#define MAX_ARGS 50

int main()
{
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS + 1];

    printf("command-line interpretator\n");
    while(1)
    {
        printf("> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "exit") == 0) 
        {

            break;
        }

        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL && i < MAX_ARGS) 
        {
            i++;
            args[i] = strtok(NULL, " ");

        pid_t pid = fork();

        if (pid < 0) {
            perror("error: creating proc");
            continue;
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("error: procces exec");
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
    }
}