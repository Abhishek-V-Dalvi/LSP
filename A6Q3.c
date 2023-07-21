/* 
Write a program which accepts directory name and file name from user and creates file in that directory3
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include<dirent.h>
#include<sys/dir.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char path[100];
    int fd = 0;

   dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    sprintf(path,"%s/%s",argv[1],argv[2]);

    fd = creat(path,0777);
    if(fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("%s File created successfuly in %s directory\n",argv[2],argv[1]);
    }

    closedir(dp);
    return 0;
}