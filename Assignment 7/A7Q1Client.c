#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    int iValue1 = 10, iValue2 = 20, iRet = 0;
    long int iRet1 = 0;
    float iRet2 = 0.0;
    void *ptr = NULL;
    void (*fptr)();

    ptr = dlopen("library.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"Addition");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    iRet = fptr(iValue1, iValue2);
    printf("Addition is : %d",iRet);

    //--------------------------------------------------------------------------

    fptr = dlsym(ptr,"Substraction");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    iRet = fptr(iValue1, iValue2);
    printf("Substraction is : %d",iRet);

    //--------------------------------------------------------------------------

    fptr = dlsym(ptr,"Multiplication");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    iRet1 = fptr(iValue1, iValue2);
    printf("Multiplication is : %ld",iRet1);

    //--------------------------------------------------------------------------

    fptr = dlsym(ptr,"Division");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    iRet2 = fptr(iValue1, iValue2);
    printf("Division is : %f",iRet2);

    //--------------------------------------------------------------------------


    return 0;
}

// gcc -rdynamic -o Myexe client.c
// gcc -ldl -o Myexe client.c

// ./Myexe