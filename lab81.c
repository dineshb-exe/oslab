#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

const int N=16;

int main(){
	int fd[2];
	char rv[16];
	int pc=pipe(fd);
	if(pc>=0){
		printf("Pipe1 successful\n");
		int pid=fork();
		wait(NULL);
		if(pid==0){
			close(fd[0]);
			printf("Child 1 writes\n");
			write(fd[1],"Hai",N);
			close(fd[1]);
			exit(0);
		}
		else{
			close(fd[1]);
			printf("Parent reads\n");
			read(fd[0],rv,N);
			printf("%s\n",rv);
			}
			int fd2[2];
			int pc2=pipe(fd2);
			if(pc2>=0){
				printf("Pipe2 successful\n");
				int pid2=fork();
				if(pid2==0){
					char rv2[16];
					close(fd2[1]);
					printf("The child 2 is reading\n");

					read(fd2[0],rv2,N);
					printf("%s\n",rv2);
					exit(0);
				}
				else{
					close(fd2[0]);
						printf("Parent writes in pipe2\n");
						write(fd2[1],rv,N);
						wait(NULL);
						exit(0);
				}
		}
	}
	else{
		printf("Pipe unsuccessful\n");
		exit(1);
	}
}
