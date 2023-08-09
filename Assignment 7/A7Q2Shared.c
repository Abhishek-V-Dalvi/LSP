#include<stdio.h>
#include "A7Q2.h"
#define BLOCKSIZE 1024


void CompFile(char Fname1[], char Fname2[])
{
    int fd1 = 0, fd2 = 0;
    struct stat obj1, obj2;
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];

    //open file
    fd1 = open(Fname1[],O_RDONLY);
    fd2 = open(Fname2[],O_RDONLY);
    
    if(fd1 == -1 || fd2 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    fstat(fd1,&obj1);
    fstat(fd2,&obj2);

    if(obj1.st_size != obj2.st_size)
    {
        printf("Files are diffrent as sizes are diffrent\n");
        return -1;
    }

    while((ret = read(fd1,Buffer1,sizeof(Buffer1))) != 0)
    {
        ret = read(fd2,Buffer2,sizeof(Buffer2));
        if(memcmp(Buffer1,Buffer2,ret) != 0)
        {
            break;
        }
    }

    if(ret == 0)
    {
        printf("Both files are identical\n");
    }
    else
    {
        printf("Both files are diffrent\n");
    }

    close(fd1);
    close(fd2);
}   


// To create .o file
// gcc -c -fPIC sharedfile.c

// To create .so file
// gcc -shared -o library.so sharedfile.o