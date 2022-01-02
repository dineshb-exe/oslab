#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t tid[3];

struct list{
  int *a;
  int size;
};

float avg;
int max1;
int min1;

void* Stats(void* arg){
  int i=0ul;
  pthread_t id = pthread_self();
  if(pthread_equal(id,tid[0])){
    printf("First Thread is executing\n");
    struct list* arr = (struct list*)arg;
    int sum=0;
    for(int i=0;i<arr->size;i++){
      sum+=arr->a[i];
    }
    avg=sum/arr->size;
  }
  else if(pthread_equal(id,tid[1])){
    printf("Second Thread is processing\n");
    struct list* arr = (struct list*)arg;
    max1 = arr->a[0];
    for(int i=1;i<arr->size;i++){
      if(arr->a[i]>max1)
      max1=arr->a[i];
    }
  }
  else{
    struct list* arr = (struct list*)arg;
    min1 = arr->a[0];
    for(int i=1;i<arr->size;i++){
      if(arr->a[i]<min1)
      min1=arr->a[i];
    }
  }

  return NULL;
}

int main(void) {
  int i=0;
  int err;
  struct list l1;
  printf("Enter the size of the array: ");
  scanf("%d", &l1.size);
  l1.a=malloc(l1.size*sizeof(int));
  printf("Enter the %d numbers:\n",l1.size);
  for(int i=0;i<l1.size;i++){
    scanf("%d",&l1.a[i]);
  }
  while(i<3){
    err = pthread_create(&(tid[i]),NULL,&Stats,&l1);
    if(err==0){
      printf("Thread %d created successfully\n",i+1);
    }
    else{
      printf("Can't create thread [%s]\n",strerror(err));
    }
    i++;
  }
  sleep(5);
  printf("The average value is %f\n",avg);
  printf("The minimum value is %d\n",min1);
  printf("The maximum value is %d\n",max1);
  return 0;
}
