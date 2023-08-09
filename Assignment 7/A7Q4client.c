#include<stdio.h>
#include "A7Q4.h"

int main()
{
    int iRet = 0, iValue = 5;

    iRet = Factorial(iValue);

    printf("Factorial is : %d\n",iRet);

    return 0;
}

// gcc client.c -o Myexe

// gcc -static client.c -o Myexe sharedfile.a

// ./Myexe
