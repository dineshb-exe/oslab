#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>
#include<sys/resource.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int pid = fork();
	if(pid!=0){
		setpriority(PRIO_PROCESS,pid,19);
    printf("\n%d %d\n",pid,getpriority(PRIO_PROCESS,pid));
		key_t key = ftok("shmfile",65);
		int shmid = shmget(key,1024,0666|IPC_CREAT);
		char p[100];
		char* str = (char*) shmat(shmid,(void*)0,0);
		//strcpy(str,"HI ");
		printf("T=Write data here \n");
		scanf("%s", str);
		printf("Data written in memory. ");
		shmdt(str);
		exit(0);
	}
	else if(pid==0) {
    printf("%d",getpid());
    //printf("%d",t);
		key_t key = ftok("shmfile",65);
		int shmid = shmget(key,1024,0666|IPC_CREAT);
		char* str = (char*) shmat(shmid,(void*)0,0);
    printf("%d",getpriority(PRIO_PROCESS,getpid()));
		printf("Data read from memory: %s\n",str);
		shmdt(str);
		shmctl(shmid,IPC_RMID,NULL);
		exit(0);
	}
	return 0;
}
