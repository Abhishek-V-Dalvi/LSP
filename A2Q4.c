/* 
Write a program which accepts directory name from user and print all file name & type of that file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    char name[30];
    char largest_name[30];
    struct stat sobj;
    int iMax = 0;
    
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
            printf("Help :\tThis application is used to print file name and\n\ttype of file in the directory.\n");
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

    //open directory file
    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    printf("\tFile name\tType of file\n");
    printf("----------------------------------------------------------\n");

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        printf("%20s\t\t%d\n",name,entry->d_type);
        
    }
    printf("----------------------------------------------------------\n");

    closedir(dp);
    
    return 0;
}