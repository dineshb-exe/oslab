#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int chopsticks[5]={1,1,1,1,1};
int times=0;
void waiter(int *x){
  while((*x)<=0);
    (*x)=0;
}
void signaller(int *x){
  (*x)+=1;
}
void* diningphilosopher(void *arg){
  int t= *(int *)arg;
  for(int i=0;i<10;i++){
    if(t%2==0){
      waiter(&chopsticks[t%5]);
      waiter(&chopsticks[(t+1)%5]);
    }
    else{
      waiter(&chopsticks[(t+1)%5]);
      waiter(&chopsticks[t%5]);
    }
    printf("Philosopher %d is dining\n",t);
    sleep(1);
    printf("Lock is released by %d\n",t);
    if(t%2==0){
      signaller(&chopsticks[t%5]);
      signaller(&chopsticks[(t+1)%5]);
    }
    else{
      signaller(&chopsticks[(t+1)%5]);
      signaller(&chopsticks[t%5]);
    }
    printf("Philosopher %d is thinking\n",t);
    times++;
  }
  pthread_detach(pthread_self());
  pthread_exit(NULL);
}
int main(){
  pthread_t ts[5];
  for(int i=0;i<5;i++){
    int *temp=&i;
    pthread_create(&ts[i],NULL,diningphilosopher,(void *)temp);
  }
  while(times<50);
  return 0;
}
