/* 
Write a program which accepts file name and mode from user and then open that file in specified mode.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = 0, Mode = 0;

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
                printf("Help :\tThis application is used to open a file in the\n\tdirectory whose name & mode is provided by user.\n");
                printf("--------------------------------------------------------\n");
                return -1;
            }
            //Usage flag
            else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
            {
                printf("---------------------------------------------\n");
                printf("Usage :\t%s File_Name Mode_Of_File\n\tuse small case to specify mode\n",argv[0]);
                printf("---------------------------------------------\n");
                return -1;
            }
        }
        return -1;
    }

    if(strcmp(argv[2],"read") == 0)
    {
        Mode = O_RDONLY;
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        Mode = O_WRONLY;
    }
    else if(strcmp(argv[2],"readwrite") == 0)
    {
        Mode = O_RDWR;
    }
    else
    {
        Mode = O_RDONLY;
    }

    //open system call
    fd = open(argv[1],Mode);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("File opened successfully with fd : %d & mode : %d\n",fd,Mode);

    //close system call
    close(fd);

    return 0;
}