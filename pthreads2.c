#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<pthread.h>


void *sorter(void *arg)
{
  int *str=(int*) arg;
  for(int i=2;i<=str[0];i++)
  {
    int temp=str[i];int j;
    for(j=i-1;j>=1 && str[j]>temp;j--)
      str[j+1]=str[j];
    str[j+1]=temp;
  }
  pthread_detach(pthread_self());
  pthread_exit(NULL);
}


void main(){
  int pr=fork();
  if(pr!=0){
    wait(NULL);
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    int *str = (int*) shmat(shmid,(void*)0,0);
    printf("Data written in memory: ");
    for(int i=1;i<=str[0];i++)
      printf("%d ",str[i]);
    pthread_t ptid;
    pthread_create(&ptid,NULL,&sorter,(void *)str);
    pthread_join(ptid, NULL);
    printf("\nDo you see any changes?\n");
    for(int i=1;i<=str[0];i++)
      printf("%d ",str[i]);
    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);
  }
  else{
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    int *str = (int*) shmat(shmid,(void*)0,0);
    if(str[0]==0)
    {
      printf("Give how many numbers: ");
      scanf("%d",str);
      printf("Give the numbers: ");
      for(int i=1;i<=str[0];i++)
        scanf(" %d",str+i);
    }
    else
    {
      for(int i=2;i<=str[0];i++)
      {
        int temp=str[i];int j;
        for(j=i-1;j>=1 && str[j]>temp;j--)
          str[j+1]=str[j];
        str[j+1]=temp;
      }
    }
    shmdt(str);
    exit(0);
  }
}
