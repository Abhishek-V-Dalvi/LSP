/*
Write a programm which accepts directory name from user and write information of all regular files and then read the content of that file
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    struct FileInfo fobj;
    int fd = 0, fd2 = 0, iRet = 0;
    char Buffer[BLOCKSIZE];

    printf("Enter name of directory : \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("AllCombine.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName,entry->d_name);
            write(fd,&fobj,sizeof(fobj));

            fd2 = open(name,O_RDONLY);
            if(fd2 == -1)
            {
                printf("Unable to open file\n");
                return -1;
            }

            while((iRet = read(fd2,Buffer,sizeof(Buffer))) != 0)
            {
                write(fd,Buffer,iRet);
            }
            close(fd2);
        }
    }

    close(fd);
    closedir(dp);
    
    return 0;
}