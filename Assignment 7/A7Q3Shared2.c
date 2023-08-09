#include<stdio.h>
#include "A7Q3.h"

void CheckPerfect(int iNo)
{
    int iCnt = 0;
    int iSum = 0;
    if(iNo < 0)
    {
        iNo = -iNo;
    }
    for(iCnt = (iNo/2); ((iCnt >= 1) && (iSum <= iNo)); iCnt--)
    {
        if((iNo % iCnt) == 0)
        {
              iSum =  iSum + iCnt;
        }
    }

    if(iSum == iNo)
    {
        printf("Number is perfect");
    }
    else
    {
        printf("Number is not perfect");
    }
}