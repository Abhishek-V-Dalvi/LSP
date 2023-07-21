/* 
Write a program which accepts directory name from user and delete all such files whose size is greater than 100bytes.
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
   
    //open directory file
    dp = opendir(argv[1]);

    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > 100)
            {
                printf("%s file with size %d bytes is removed \n",name,sobj.st_size);
                remove(name);
            }
        }
    }

    closedir(dp);
    
    return 0;
}