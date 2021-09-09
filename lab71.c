#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
  int a=10;
  int b=20;
  int p_id=vfork();// vfork = fork but parent process is suspended until child executes. vfork's behavior is unpredictable
  if(p_id==0){
    printf("I am a child process! \n");
    a=a+20;
    b=b-10;
    exit(0);
  }
  else{
//    wait(NULL);
    printf("I am the parent Process! \n");
    a=a-20;
    b=b+10;
    printf("Sum: %d\n",a+b);
  }
}
