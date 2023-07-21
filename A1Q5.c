/* 
Write a program which accepts file name and number of bytes from user and read that number of bytes from file.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define BLOKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0, iRet = 0, size = 0;
    char *buffer = NULL;

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
                printf("Help :\tThis application is used to read specified number\n\tof bytes from file.\n");
                printf("--------------------------------------------------------\n");
                return -1;
            }
            //Usage flag
            else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
            {
                printf("---------------------------------------------\n");
                printf("Usage :\t%s File_Name Number_Of_Bytes\n",argv[0]);
                printf("---------------------------------------------\n");
                return -1;
            }
        }
        return -1;
    }

    //open file
    fd = open(argv[1],O_RDONLY);

    //Check whether file opened or not
    if(fd == -1)
    {
        printf("Unable to open file : %s\n",argv[1]);
    }

    size = atoi(argv[2]);

    //Dynamic sizing of buffer
    buffer = (char *)malloc(size);

    //read
    iRet = read(fd,buffer,size);

    if(iRet == 0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    //Write
    write(1,buffer,iRet);

    close(fd);
    
    return 0;
}