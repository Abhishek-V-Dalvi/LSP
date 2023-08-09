#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int iRet1 = 0, iRet2 = 0, iRet3 = 0;

    iRet1 = fork();
    iRet2 = fork();
    iRet3 = fork();

    if(iRet1 == 0 && iRet2 > 0 && iRet3 > 0)  // Child  
    {
        printf("First child with PID : %d\n",getpid());
    }
    else if(iRet2 == 0 && iRet1 > 0 && iRet3 > 0)  // Child  
    {
        printf("Second child with PID : %d\n",getpid());
    }
    else if(iRet3 == 0 && iRet1 > 0 && iRet2 > 0)  // Child  
    {
        printf("Third child with PID : %d\n",getpid());
    }
    else if (iRet1 > 0 && iRet2 > 0 && iRet3 > 0)     // Parent
    {
        printf("Parent is running with PID : %d\n",getpid());
      
    }

    return 0;
}