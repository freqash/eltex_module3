#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int max(int argc, char * argv[])
{
    int result = 0;
    for(int i = 1; i < argc; i++)
    {
        if(atoi(argv[i]) > result)
        {
            result = atoi(argv[i]);
        }
        else
        {
            continue;
        }
    }
    printf("result: %d\n", result);
    return(result);
}