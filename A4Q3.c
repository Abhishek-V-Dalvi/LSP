/* 
Write a program which accepts two file names from user and check the content of that file is same or not.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd1 = 0, fd2 = 0, ret = 0;
    struct stat obj1, obj2;
    char Buffer1[BLOCKSIZE];
    char Buffer2[BLOCKSIZE];

    //Filter for command line arguments
    if(argc != 3)
    {
        printf("----------------------------------------------\n");
        printf("Insufficient number of argument\n\n");
        printf("Number of argument should be : 3\nUse flag as below\n");
        printf("-h for help\n-u for usage\n");
        printf("----------------------------------------------\n");

        if(argc == 2)
        {
            //Help flag
            if ((strcmp(argv[1],"-h") == 0) || (strcmp(argv[1],"-H") == 0))
            {
                printf("--------------------------------------------------------\n");
                printf("Help :\tThis application is used to check whether content of\n\ttwo files are same or not.\n");
                printf("--------------------------------------------------------\n");
                return -1;
            }
            //Usage flag
            else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
            {
                printf("---------------------------------------------\n");
                printf("Usage :\t%s First_File_Name Second_File_Name\n",argv[0]);
                printf("---------------------------------------------\n");
                return -1;
            }
        }
        return -1;
    }

    //open file
    fd1 = open(argv[1],O_RDONLY);
    fd2 = open(argv[2],O_RDONLY);
    
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
    return 0;
}