/* 
Write a program which accepts directory name and file names from user and check whether the file is present in that diectory or not.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include<dirent.h>
#include<sys/dir.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;

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
                printf("Help :\tThis application is used to check whether file\n\tis present in directory or not.\n");
                printf("--------------------------------------------------------\n");
                return -1;
            }
            //Usage flag
            else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
            {
                printf("---------------------------------------------\n");
                printf("Usage :\t%s Directory_Name File_Name\n",argv[0]);
                printf("---------------------------------------------\n");
                return -1;
            }
        }
        return -1;
    }

   dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open the directory\n");
        return -1;
    } 

    while((entry = readdir(dp)) != NULL)
    {

        if((strcmp(argv[2], entry->d_name)) == 0)
        {
            printf("File is present in directory\n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("There is no such file\n");
        return -1;
    }

    closedir(dp);
    return 0;
}