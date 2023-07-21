/* 
Write a program which accepts file name and mode from user and that program will check whether
our process can access that file in accepted mode or not
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
                printf("Help :\tThis application is used to check whether process can access that file in the\n\tgiven mode.\n");
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
        Mode = R_OK;
    }
    else if(strcmp(argv[2],"write") == 0)
    {
        Mode = W_OK;
    }
    else if(strcmp(argv[2],"execute") == 0)
    {
        Mode = X_OK;
    }

    if(access(argv[1],Mode) < 0)
    {
        printf("Unable to access %s file in %s mode \n", argv[1],argv[2]);
    }
    else
    {
        printf("You can access %s file in %s mode \n", argv[1],argv[2]);
    }

    return 0;
}