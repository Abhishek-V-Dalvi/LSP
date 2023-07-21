/* 
Write a program which accepts two file names from user and copy content of existig file into another file.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    int Ret = 0;
    char Buffer[BLOCKSIZE] = {'\0'};

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
                printf("Help :\tThis application is used to copy content of\n\tone file into another.\n");
                printf("--------------------------------------------------------\n");
                return -1;
            }
            //Usage flag
            else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
            {
                printf("---------------------------------------------\n");
                printf("Usage :\t%s Source_File_Name Dest_File_Name\n",argv[0]);
                printf("---------------------------------------------\n");
                return -1;
            }
        }
        return -1;
    }

    //open file
    fdSource = open(argv[1],O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open source file\n");
        return -1;
    }

    fdDest = creat(argv[2],0777);
    if(fdDest == -1)
    {
        printf("Unable to create destination file\n");
        close(fdSource);
        return -1;
    }

    while((Ret = read(fdSource,Buffer,sizeof(Buffer))) != 0)
    {
        write(fdDest,Buffer,Ret);
        memset(Buffer,0,sizeof(Buffer));
    }

    close(fdSource);
    close(fdDest);
    return 0;
}