#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv[])
{
    pid_t pid;
    if(argc <= 1)
    {
        printf("synopsis: \n\t%s [SIZES]\nexample: %s 2 5 7\n", argv[0], argv[0]);
    }
    else
    {
        switch(pid = fork()) {
            case -1:
                perror("fork");
                exit(EXIT_FAILURE);
            case 0:
                for(int i = 1; i < argc; i+=2)
                {
                    int arg = atoi(argv[i]);
                    int result = arg*arg;
                    printf("result for arg %d: %d PID0: %d\n", arg, result, getpid());
                }
                exit(EXIT_SUCCESS);
            default:
                for(int i = 2; i < argc; i+=2)
                {
                    int arg = atoi(argv[i]);
                    int result = arg*arg;
                    printf("result for arg %d: %d PIDD: %d\n", arg, result, getpid());
                }
                exit(EXIT_SUCCESS);
        }

    }
}