/* 
Write a program which accepts directory name from user and copy first 10 bytes from all the regular files into newly created file demo.txt.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, iRet = 0;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    char buffer[10];
    struct stat sobj;


    //Filter for command line arguments
    if(argc != 2)
    {
        printf("----------------------------------------------\n");
        printf("Insufficient number of argument\n\n");
        printf("Number of argument should be : 2\nUse flag as below\n");
        printf("-h for help\n-u for usage\n");
        printf("----------------------------------------------\n");

        return -1;
    }

    if(argc == 2)
    {
        //Help flag
        if ((strcmp(argv[1],"-h") == 0) || (strcmp(argv[1],"-H") == 0))
        {
            printf("--------------------------------------------------------\n");
            printf("Help :\tThis application is used to copy first 10 bytes of all\n\tregular files from the directory and copy that\n\tinto a new file named as Demo.txt.\n");
            printf("--------------------------------------------------------\n");
            return -1;
        }
        //Usage flag
        else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
        {
            printf("---------------------------------------------\n");
            printf("Usage :\t%s Directory_Name\n",argv[0]);
            printf("---------------------------------------------\n");
            return -1;
        }
    }

    fd1 = creat("Demo.txt",0777);
    if(fd1 == -1)
    {
        printf("Unable to create file\n");
        return -1;
    }

    fd1 = open("Demo.txt",O_RDWR);
    if(fd1 == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fd2 = open(name,O_RDONLY);
            if(fd2 == -1)
            {       
                 printf("Unable to open file\n");
                return -1;
            }

            iRet = read(fd2,buffer,10);

            write(fd1,buffer,iRet);

        }
    }

    close(fd1);
    close(fd2);
    closedir(dp);
    
    return 0;
}