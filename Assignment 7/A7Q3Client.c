#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc, char *argv[])
{
    int iValue = 0;

    ptr1 = dlopen("library1.so",RTLD_LAZY);
    ptr2 = dlopen("library2.so",RTLD_LAZY);
    if((ptr1 == NULL) || (ptr2 == NULL))
    {
        printf("Unable to load liabrary\n");
        return -1;
    }

    fptr = dlsym(ptr,"CheckPrime");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    iValue = atoi(argv[1]);

    fptr(iValue);

    fptr = dlsym(ptr,"CheckPerfect");
    if(fptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }
    fptr(iValue);
    
    return 0;
}

// gcc -rdynamic -o Myexe client.c
// gcc -ldl -o Myexe client.c

// ./Myexe