#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sched.h>
#include<string.h>
#include <sys/time.h>
#include<math.h>
void print_gantt_chart(float arr[],char **argv, int n)
{
    int i, j;
    // print top bar
    printf(" ");
    for(i=1,j=0; i<n; i++) {
        for(; j<arr[i]/10; j++) printf("--");//arr contains waitimg time.
        printf(" ");
    }
    printf("\n|");
 
    // printing process id in the middle
    for(i=1,j=0; i<n; i++) {
        for(; j<(int)(arr[i]/10); j++) printf(" ");
        printf("p%d",i);
        j=(arr[i-1]/10)+1;
        for(; j<(int)(arr[i]/10); j++) printf(" ");
        printf("|");
        j=(int)(arr[i]/10);
    }
    printf("\n ");
    // printing bottom bar
    for(i=1,j=0; i<n; i++) {
        for(; j<arr[i]/10; j++) printf("--");
        printf(" ");
    }
    printf("\n");
 
    // printing the time line
    printf("0");
    for(i=1,j=0; i<n; i++) {
        for(; j<arr[i]/10; j++) printf("  ");
        printf("%d", (int)ceil(arr[i]));
        j+=i;
 
    }
    printf("\n");
 
}



int middleman(char *process)
{
  execl("/bin/bash","bash","/home/rebirth/runprogcmd.sh",(char *) process,NULL);
  return 0;
}

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void findWaitingTime(int n, float bt[], float wt[])
{
    wt[0] = 0;

    for (int  i = 1; i < n ; i++ )
        wt[i] =  bt[i-1] + wt[i-1] ;
}


void findavgTime(const int n, float bt[],float wt[])
{
    float total_wt = 0, total_tat = 0;

    findWaitingTime(n, bt, wt);

    for (int  i=1; i<n; i++)
    {
        total_wt = total_wt + wt[i-1];
        total_tat = total_tat + wt[i];
    }
    float s=(float)total_wt / (float)(n-1);
    float t=(float)total_tat / (float)(n-1);
    printf("Average waiting time = %f\n",s);
    printf("Average turn around time = %f \n",t);
}
void main(int argc, char **argv)
{
  //arrival time is 0 for all processes
  const int count=argc;
  float burst_time[count];
  float waiting_time[count];
  int status;
  for(int i=1;i<argc;i++)
  {
      char *stack;
	  char *stackhead;
	  pid_t pid;
	  struct timeval t0,t1;
   	  float elapsed;
	  stack= (char *) malloc(1024*1024);
	  if(!stack)
	  {
		   printf("bye!");
		   exit(1);
	  }
	  stackhead=stack + (1024*1024) -1;
	  gettimeofday(&t0, 0);
	  pid=clone(middleman, stackhead, SIGCHLD, argv[i]);
	  waitpid(pid,&status,0);
	  gettimeofday(&t1, 0);
    elapsed = timedifference_msec(t0, t1);
    burst_time[i-1]=elapsed;
    free(stack);
  }
  findavgTime(count,  burst_time,waiting_time);
  print_gantt_chart(waiting_time,argv,argc);
}
