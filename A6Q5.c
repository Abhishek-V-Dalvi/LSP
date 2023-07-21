/* 
Write a program which accepts  name of file and offset from user and remove all data from that offset.
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
    int fd = 0, pos = 0, trunc = 0, seek = 0;
    struct stat sobj;    
    

    fd = open(argv[1],O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open the file\n");
        return -1;
    }

    stat(argv[1],&sobj);

    pos = atoi(argv[2]);

    seek = lseek(fd,pos,0);
    if(seek == -1)
    {
        printf("Lseek unsuccessfull\n");
        return -1;
    }
    
    trunc = truncate(argv[1],(sobj.st_size - pos));

    if(trunc == 0)
    {
        printf("Success\n");
    }
    else
    {
        printf("Failure\n");
    }

    return 0;
}