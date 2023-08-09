#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    int Child_PID = 0;
    int Exit_Status = 0;

    iRet = fork();

    if(iRet == 0)  // Child  
    {
        execl("./ChildProcess1","NULL",NULL);       //Child1.c
    }
    else        // Parent
    {
        printf("Parent is running with PID : %d\n",getpid());
        Child_PID = wait(&Exit_Status);
        printf("Child process1 terminated having PID %d with exit status %d\n",Child_PID,Exit_Status);
    }

    return 0;
}