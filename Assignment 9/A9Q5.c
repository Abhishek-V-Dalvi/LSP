#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sched.h>

int main()
{
    int Ret = 0;

    Ret = sched_yield();

    if(Ret == 0)
    {
        printf("Successs\n");
    }
    else if(Ret == -1)
    {
        printf("Failure\n");
    }

    printf("End of main thread\n");

    return 0;
}

