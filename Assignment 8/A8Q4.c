#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int iRet1 = 0, iRet2 = 0;
    int Child_PID = 0;
    int Exit_Status = 0;

    iRet1 = fork();
    iRet2 = fork();

    if(iRet1 == 0 && iRet2 > 0)  // Child  
    {
        execl("./ChildProcess3","NULL",NULL);       //Child1.c
    }
    else if(iRet2 == 0 && iRet1 > 0)  // Child  
    {
        execl("./ChildProcess4","NULL",NULL);       //Child2.c
    }
    else if (iRet1 > 0 && iRet2 > 0)     // Parent
    {
        printf("Parent is running with PID : %d\n\n",getpid());
        Child_PID = wait(&Exit_Status);
        printf("Child process1 terminated having PID %d with exit status %d\n",Child_PID,Exit_Status);
      Child_PID = wait(&Exit_Status);
        printf("Child process2 terminated having PID %d with exit status %d\n",Child_PID,Exit_Status);
    }

    return 0;
}