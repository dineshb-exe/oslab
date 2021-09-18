#include<stdio.h>
	#include<stdlib.h>
	#define MAX 99999
	struct process	{
  	int arrival_time;
  	int burst_time;
  	int temp;
	}p[10];
	struct gantt{
	  int p[100];
 	 int t[100];
	}x;
	int main(){
 	 int n;
 	 printf("Enter the number of processes: ");
 	 scanf("%d", &n);
  	for(int i=0;i<n;i++) {
  	  printf("\nEnter process %d details: \n", i+1);
    	printf("Enter arrival time: ");
   	 scanf("%d", &p[i].arrival_time);
    	printf("Enter burst time: ");
    	scanf("%d", &p[i].burst_time);
   	 p[i].temp = p[i].burst_time;}
  	int count=0, smallest;
  	float completion_time, turn_around_time=0, wait_time=0;
  	p[9].burst_time = MAX;


	  int j=0,k=0;
  	for(int time=0;count!=n;time++) {
    	smallest = 9;
    	for(int i=0;i<n;i++){
      	if(p[i].arrival_time <= time && p[i].burst_time < p[smallest].burst_time && p[i].burst_time > 0)
        	smallest = i;}
    	p[smallest].burst_time--;
   	if(p[smallest].burst_time==0){
      	count++;
      	completion_time = time+1;
      printf("\nCompletion Time for P%d: %f ms\n", smallest+1, completion_time);
      printf("Turnaround Time for P%d: %f ms\n", smallest+1, completion_time-     	p[smallest].arrival_time);
      printf("Wait Time for P%d: %f ms\n", smallest+1, completion_time- p[smallest].arrival_time - p[smallest].temp);
      turn_around_time = turn_around_time +completion_time - p[smallest].arrival_time;
      wait_time = wait_time + completion_time - p[smallest].arrival_time - p[smallest].temp;

    }
// accumulating processes and their corresponding time interval
    if(smallest!=9){
      x.p[j++] = smallest+1;
      x.t[k++] = time;}
  }
  float avg_turn_around_time = turn_around_time/n;
  float avg_wait_time = wait_time/n;
  printf("Average turn around time: %f ms\n", avg_turn_around_time);
  printf("Average waiting time: %f ms\n" , avg_wait_time);
  printf("\n Gantt Chart for SJF Pre-emptive\n");
  int duration[1000], r=0;


for(int i=0;i<j;i++) {
    if(i==0){
      printf("P%d   " , x.p[i]);
      duration[r++] = x.t[i];
    }
    else if(x.p[i]!=x.p[i-1]){
      printf("P%d   " , x.p[i]);
      duration[r++] = x.t[i];
    }
  }
  printf("\n");
  for(int i=0;i<r+1;i++)
    printf("|    ");
  printf("\n");
  for(int i=0;i<r;i++) {
      printf("%d   " , duration[i]);
  }
  printf("%d" , x.t[k-1]+1);
  return 0;
}
