#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    int Child_PID = 0;
    int Exit_Status = 0;

    printf("Hello I am a first child process. My parent is waiting till my execution gets finished.\n");

    iRet = fork();

    if(iRet == 0)  // Child  
    {
        execl("./ChildProcess2","NULL",NULL); //Child2.c
    }
    else        // Parent
    {
        printf("First child is running with PID : %d\n",getpid());
        Child_PID = wait(&Exit_Status);
        printf("Child process2 terminated having PID %d with exit status %d\n",Child_PID,Exit_Status);
    }

    return 0;
}