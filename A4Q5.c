/* 
Write a programm which accepts file name and position from user and reads 20 bytes from that position
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int fd = 0, iRet = 0;
    char buffer[20];

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
                printf("Help :\tThis application is used to read 20 bytes from the file\n\tfrom the given location.\n");
                printf("--------------------------------------------------------\n");
                return -1;
            }
            //Usage flag
            else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
            {
                printf("---------------------------------------------\n");
                printf("Usage :\t%s File_Name Position\n",argv[0]);
                printf("---------------------------------------------\n");
                return -1;
            }
        }
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1)
    {       
            printf("Unable to open file\n");
        return -1;
    }

    lseek(fd,atoi(argv[2]),0);

    iRet = read(fd,buffer,20);

    printf("Data from file is \n");

    write(1,buffer,iRet);

    
    close(fd);

 
    return 0;
}