#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t tid[2];

void* Chumma(void* arg){
  int i=0ul;
  pthread_t id = pthread_self();
  if(pthread_equal(id,tid[0])){
    printf("First Thread is executing\n");
  }
  else{
    printf("Second Thread is processing\n");
  }
  for(int i=0;i<0xFFFFFFFF;i++);
  return NULL;
}

int main(void) {
  int i=0;
  int err;
  while(i<2){
    err = pthread_create(&(tid[i]),NULL,&Chumma,NULL);
    if(err==0){
      printf("Thread created successfully\n");
    }
    else{
      printf("Can't create thread [%s]\n",strerror(err));
    }
    i++;
  }
  sleep(5);
  return 0;
}
