/* 
Write a program which accepts file name from user and write string in that file.
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
    char Str [100];
    
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
            printf("Help :\tThis application is used to write string in the\n\tfile.\n");
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

    printf("Enter the string that you want to write in the file\n");
    scanf("%[^\n]s",Str);

    iRet = strlen(Str);

    //open file
    fd = open(argv[1],O_WRONLY);

    //Check whether file opened or not
    if(fd == -1)
    {
        printf("Unable to open file : %s\n",argv[1]);
    }

    //Write
    write(fd,Str,iRet);

    close(fd);
    
    return 0;
}