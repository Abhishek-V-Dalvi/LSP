#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer [50];
    DIR *dp = NULL;
    struct dirent * entry = NULL;

    printf("Inside child\n");

    fd = creat("Demo.txt",0777);
    if(fd == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    fd = open("Demo.txt",O_WRONLY);
    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    dp = opendir("/home/abhishek/Desktop");
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        strcpy(Buffer,entry->d_name);
        //printf("%s\n",entry->d_name);
        write(fd,Buffer,sizeof(Buffer));
    }
    printf("----------------------------------------------------------\n");

    close(fd);
    closedir(dp);
    return 0;
}