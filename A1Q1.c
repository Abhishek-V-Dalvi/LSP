/* 
Write a program which accepts file name from user and open that file.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = 0;

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

    //Help flag
    if ((strcmp(argv[1],"-h") == 0) || (strcmp(argv[1],"-H") == 0))
    {
        printf("--------------------------------------------------------\n");
        printf("Help :\tThis application is used to open a file in the\n\tdirectory whose name is provided by user.\n");
        printf("--------------------------------------------------------\n");
        return -1;
    }
    //Usage flag
    else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
    {
        printf("---------------------------------------------\n");
        printf("Usage :\t%s File_Name\n",argv[0]);
        printf("---------------------------------------------\n");
        return -1;
    }

    //open system call
    fd = open(argv[1],O_RDWR);

    if(fd == -1)
    {
        printf("Unable to open file\n");
        return -1;
    }

    printf("File opened successfully with fd : %d\n",fd);

    //close system call
    close(fd);

    return 0;
}