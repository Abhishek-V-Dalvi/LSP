#include<stdio.h>
#include "A7Q1.h"

int Addition(int iNO1, int iNo2)
{
    int iAns = 0;

    iAns = iNO1 + iNo2;

    return iAns;
}

int Substraction(int iNO1, int iNo2)
{
    int iAns = 0;

    if(iNO1 > iNo2)
    {
        iAns = iNO1 - iNo2;
    }
    else
    {
        iAns = iNO2 - iNo1;
    }
    return iAns;
}

long int Multiplication(int iNO1,int iNO2)
{
    long int iAns = 0;

    iAns = iNO1 * iNO2;

    return iAns;
}

float Division(int iNO1,int iNO2)
{
    float iAns = 0;

    if(iNO2 == 0)
    {
        printf("Denominator can not be zero");

        return iAns;
    }
    
    iAns = iNO1 / iNO2;

    return iAns;
}


// To create .o file
// gcc -c -fPIC sharedfile.c

// To create .so file
// gcc -shared -o library.so sharedfile.o