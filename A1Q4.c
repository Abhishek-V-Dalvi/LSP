/* 
Write a program which accepts file name from user and print all information of that file.
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat sobj;

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
        printf("-----------------------------------------------------------------------\n");
        printf("Help :\tThis application is used to print all information of the file.\n");
        printf("-----------------------------------------------------------------------\n");
        return -1;
    }
    //Usage flag
    else if ((strcmp(argv[1],"-u") == 0) || (strcmp(argv[1],"-U") == 0))
    {
        printf("---------------------------------------------\n");
        printf("Usage :\t%s File_Name \n",argv[0]);
        printf("---------------------------------------------\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("---------------------------------------------\n");
    printf("File name\t\t: %s\n",argv[1]);
    printf("---------------------------------------------\n");
    printf("File size is\t\t: %ld\n",sobj.st_size);
    printf("---------------------------------------------\n");
    printf("Number of links\t\t: %ld\n",sobj.st_nlink);
    printf("---------------------------------------------\n");
    printf("Inode number\t\t: %ld\n",sobj.st_ino);
    printf("---------------------------------------------\n");
    printf("File system number\t: %ld\n",sobj.st_dev);
    printf("---------------------------------------------\n");
    printf("Number of blocks\t: %ld\n",sobj.st_blocks);
    printf("---------------------------------------------\n");
    printf("Permissions of file\t: %d\n",sobj.st_mode);
    printf("---------------------------------------------\n");
    
    return 0;
}