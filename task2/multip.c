#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int multip(int argc, char * argv[])
{
    int result = 0;
    for(int i = 1; i < argc; i++)
    {
        result *= atoi(argv[i]);
    }
    printf("result: %d\n", result);
    return(result);
}