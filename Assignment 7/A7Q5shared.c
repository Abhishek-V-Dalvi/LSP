#include <stdio.h>
#include <sys/stat.h>
#include "A7Q5.h"

void FileInfo(char FileName[])
{
    struct stat sobj;

    stat(FileName,&sobj);

    printf("---------------------------------------------\n");
    printf("File name\t\t: %s\n",FileName);
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
}

// convert .c to .o
// gcc -c sharedfile.c -o sharedfile.o

// convert .o to .a
// ar rcs sharedfile.a sharedfile.o

