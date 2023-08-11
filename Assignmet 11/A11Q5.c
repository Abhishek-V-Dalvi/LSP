#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
  int fd = 0, iRet = 0, iCnt = 0;
  char Buffer[512];

  fd = (int)ptr;

  lseek(fd,SEEK_SET,0);


  while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
  {
      for(int i = 0; i < iRet ; i++)
      {
          if((Buffer[i] >= 'a') && (Buffer[i] <= 'z'))
          {
              iCnt++;
          }
      }
  }
  pthread_exit(iCnt);
}

void * ThreadProc2(void *ptr)
{
  int fd = 0, iRet = 0, iCnt = 0;
  char Buffer[512];

  fd = (int)ptr;

  lseek(fd,SEEK_SET,0);


  while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
  {
      for(int i = 0; i < iRet ; i++)
      {
          if((Buffer[i] >= 'A') && (Buffer[i] <= 'Z'))
          {
              iCnt++;
          }
      }
  }

  pthread_exit(iCnt);
}

int main()
{
    pthread_t TID1, TID2;
    int ret = 0, ret2 = 0, fd = 0;
    int value1 = 0 , value2 = 0;

    fd = open("Hello.txt",O_RDONLY);

    if(fd == -1)
    {
      printf("Unable to open file\n");
      return -1;
    }


    ret = pthread_create(&TID1,            // Address of pthread_attr_t structure object
                          NULL,           // Thread attributes
                          ThreadProc1,     // Address of callback function
                          (int *)fd);     // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    
    ret2 = pthread_create(&TID2,            // Address of pthread_attr_t structure object
                          NULL,           // Thread attributes
                          ThreadProc2,     // Address of callback function
                          (int *)fd);     // Parameters to callback function

    if(ret2 != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }

    
    pthread_join(TID1,&value1);
    pthread_join(TID2,&value2);
    printf("Number of Small characters are : %d\n",value1);
    printf("Number of Capital characters are : %d\n",value2);

    close(fd);

    printf("End of main thread\n");
    return 0;
}