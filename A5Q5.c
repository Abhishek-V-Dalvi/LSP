/*
Write a programm which accepts file name which contains data of all regular files we have to create all files again.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#define BLOCKSIZE 1024

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char name[20];
    struct stat sobj;
    struct FileInfo fobj;
    int fd = 0, fd2 = 0, iRet = 0, size = 0;
    char Buffer[BLOCKSIZE];
    char sizearr[4]; 

    fd = open("AllCombine.txt",O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    sprintf(name,"%s",read(fd,name,20));

    fd2 = creat(name,0777);
    if(fd2 == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }
    
    size = atoi(read(fd,sizearr,4));
    
    while((iRet = read(fd,Buffer,size)) != 0)
    {
        write(fd2,Buffer,iRet);
    }
   
   
   
    close(fd2);
    close(fd); 
    return 0;
}