#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
  key_t key = 677;

  int shmid = shmget(key,1024,0666|IPC_CREAT);

  char *str = (char*) shmat(shmid,(void*)0,0);

  printf("Write Data : ");
  scanf(" %[^\n]",str);

  printf("Data written in memory: %s\n",str);

  shmdt(str);
  exit(0);
  return 0;
}
