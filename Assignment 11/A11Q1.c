#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

void * ThreadProc1(void *ptr)
{
  printf("Inside Thread 1\n");

}

void * ThreadProc2(void *ptr)
{
 printf("Inside Thread 2\n");
}

void * ThreadProc3(void *ptr)
{
  printf("Inside Thread 3\n");

}

void * ThreadProc4(void *ptr)
{
  printf("Inside Thread 4\n");

}

int main()
{
    pthread_t TID1, TID2, TID3, TID4;
    int ret = 0;

    ret = pthread_create(&TID1,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc1, // Address of callback function
                          NULL);      // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread1 is created with ID : %ld\n",TID1);

  //---------------------------------------------------------------------------------------

    ret = pthread_create(&TID2,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc2, // Address of callback function
                          NULL);      // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread2 is created with ID : %ld\n",TID2);

    //---------------------------------------------------------------------------------------
  
    ret = pthread_create(&TID3,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc3, // Address of callback function
                          NULL);      // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread3 is created with ID : %ld\n",TID3);

    //---------------------------------------------------------------------------------------
  
    ret = pthread_create(&TID4,        // Address of pthread_attr_t structure object
                          NULL,       // Thread attributes
                          ThreadProc4, // Address of callback function
                          NULL);      // Parameters to callback function

    if(ret != 0)
    {
      printf("Unable to create thread\n");
      return -1;
    }
    printf("Thread4 is created with ID : %ld\n",TID4);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);
    pthread_join(TID3,NULL);
    pthread_join(TID4,NULL);


    printf("End of main thread\n");
    
    pthread_exit(NULL);
    return 0;
}