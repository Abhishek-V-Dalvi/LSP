/* 
Write a program which used to demonstrate the concept of I/O redirection..

./Exe <Input_File_Name >Output_File_Name
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0;
    int iAns = 0;

    scanf("%d",&iNo1);
    scanf("%d",&iNo2);

    iAns = iNo1 + iNo2;

    printf("Addition is : %d\n",iAns);

    return 0;
}