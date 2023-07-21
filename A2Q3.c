/* 
Write a program which accepts directory name from user and print all filenames from that directory.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    
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
            printf("Help :\tThis application is used to print all file names\n\tfrom the given directory.");
            printf("--------------------------------------------------------\n");
            return -1;
        }
        //Usage flag
        else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
        {
            printf("---------------------------------------------\n");
            printf("Usage :\t%s Directory_Name\n",argv[0]);
            printf("---------------------------------------------\n");
            return -1;
        }
    }

    //open file
    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }
    printf("----------------------------------------------------------\n");
    printf("Entries from the directory file are : \n");
    printf("----------------------------------------------------------\n");
    printf("File Name\n");

    while((entry = readdir(dp)) != NULL)
    {
        printf("%s\n",entry->d_name);
    }
    printf("----------------------------------------------------------\n");

    closedir(dp);
    
    return 0;
}