#include<stdio.h>
#include "A7Q3.h"


void CheckPrime(int iNo)
{
    int iCnt = 0;

    for(iCnt = 2; iCnt <= (iNo/2); iCnt++)
    {
        if(iNo % iCnt == 0)     
        {
            break;
        }
    }

    if(iCnt == (iNo/2) + 1)
    {
        printf("Number is prime");
    }
    else
    {
        printf("Number is not prime");
    }

}




// To create .o file
// gcc -c -fPIC sharedfile.c

// To create .so file
// gcc -shared -o library.so sharedfile.o