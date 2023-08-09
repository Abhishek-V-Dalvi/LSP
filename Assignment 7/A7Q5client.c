#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "A7Q5.h"

int main(int argc, char *argv[])
{
    FileInfo(argv[1]);

    return 0;
}

// gcc client.c -o Myexe

// gcc -static client.c -o Myexe sharedfile.a

// ./Myexe
