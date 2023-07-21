/* 
Write a program which accepts file name from user and read whole file.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BLOKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0, iRet = 0;
    char buffer [BLOKSIZE];

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
            printf("Help :\tThis application is used to read whole filer\n");
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
    }

    //open file
    fd = open(argv[1],O_RDONLY);

    //Check whether file opened or not
    if(fd == -1)
    {
        printf("Unable to open file : %s\n",argv[1]);
    }

    //read
    while ((iRet = read(fd,buffer,sizeof(buffer))) != 0)
    {
        //Write
        write(1,buffer,iRet);
    }

    close(fd);
    
    return 0;
}