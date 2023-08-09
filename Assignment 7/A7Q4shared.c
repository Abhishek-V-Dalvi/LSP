#include "A7Q4.h"

int Factorial(int iNo)
{
    int iFact = 1;
    int iCnt = 0;

    for(iCnt = 1; iCnt <= iNo; iCnt++)
    {
        iFact *= iCnt; 
    }
    return iFact;
}

// convert .c to .o
// gcc -c sharedfile.c -o sharedfile.o

// convert .o to .a
// ar rcs sharedfile.a sharedfile.o

