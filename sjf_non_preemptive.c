#include<stdio.h>
typedef struct Process
{
int process_id;
nt arr_time;
int burst_time;
int finish_time;
int wait_time;
int ta_time;
}process;
void swap(process *proc1,process *proc2)
{
process temp=*proc1;
*proc1=*proc2;
*proc2=temp;
}
int arrangeArrival(int num, process proc[])
{
int i,j,k,flag=0;
for(i=0;i<num;i++)
{
for(j=0;j<num-i-1;j++)
{
if(proc[j].arr_time>proc[j+1].arr_time)
{
flag=1;
for(k=0;k<num-1;k++)
{
swap(&proc[j],&proc[j+1]);
}
}
}
}
return flag;
}
void burstTime(int num, process proc[])
{
int i,j,k;
for(i=0;i<num;i++)
{
for(j=0;j<num-i-1;j++)
{
if(proc[j].burst_time>proc[j+1].burst_time)
{
for(k=0;k<num-1;k++)
{
swap(&proc[j],&proc[j+1]);
}
}
}
}
}
void completionTime(int num,process proc[])
{
int temp,val,i,j,k;
proc[0].finish_time=proc[0].arr_time+proc[0].burst_time;
proc[0].ta_time=proc[0].finish_time-proc[0].arr_time;
proc[0].wait_time=proc[0].ta_time-proc[0].burst_time;
for(i=1;i<num;i++)
{
temp=proc[i-1].finish_time;
int low=proc[i].burst_time;
for(j=i;j<num;j++)
{
if(temp>=proc[j].arr_time&& low>=proc[j].burst_time)
{
low=proc[j].burst_time;
val=j;
}
}
proc[val].finish_time=temp+proc[val].burst_time;
proc[val].ta_time=proc[val].finish_time-proc[val].arr_time;
proc[val].wait_time=proc[val].ta_time-proc[val].burst_time;
for(k=0;k<num-1;k++)
{
swap(&proc[val],&proc[i]);
}
}
}
void printganttchart(process proc[],int num)
{
int i;
printf("\nGantt chart:\n");
for(i=0;i<num;i++)
{
printf("_");
}
printf("\n");
for(i=0;i<num;i++)
{
  printf("|P%d\t",proc[i].process_id);
}
printf("|\n");
for(i=0;i<num;i++)
{
printf("_");
}
printf("\n0\t");
for(i=0;i<num;i++)
{
printf("|%d\t",proc[i].finish_time);
}
printf("\n");
}
int main()
{
int num;
printf("Enter the Number of processes: ");
scanf("%d",&num);
process proc[num];
int i;
for(i=0;i<num;i++)
{
printf("\nProcess no. : %d\nEnter Process ID: ",i+1);
scanf("%d",&proc[i].process_id);
printf("Enter Arrival time: ");
scanf("%d",&proc[i].arr_time);
printf("Enter Burst time: ");
scanf("%d",&proc[i].burst_time);
}
int flag;
flag=arrangeArrival(num,proc);
printf("\nPerformance Statistics: \n");
printf("\nID\tA_time\tB_time\tF_time\tW_time\tTa_time\n");
float avg_wt=0,avg_ta=0;
for(i=0;i<num;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].process_id,proc[i].arr_time,
proc[i].burst_time,proc[i].finish_time,proc[i].wait_time,proc[i].ta_time);
avg_wt+=proc[i].wait_time;
avg_ta+=proc[i].ta_time;
}
if(flag==0)
{
burstTime(num,proc);
}
printf("\nPerformance Statistics: \n");
printf("\nID\tA_time\tB_time\tF_time\tW_time\tTa_time\n");
//float avg_wt=0,avg_ta=0;
for(i=0;i<num;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].process_id,proc[i].arr_time,
proc[i].burst_time,proc[i].finish_time,proc[i].wait_time,proc[i].ta_time);
avg_wt+=proc[i].wait_time;
avg_ta+=proc[i].ta_time;
}
completionTime(num,proc);
printf("\nPerformance Statistics: \n");
printf("\nID\tA_time\tB_time\tF_time\tW_time\tTa_time\n");
//float avg_wt=0,avg_ta=0;
for(i=0;i<num;i++)
{
printf("%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].process_id,proc[i].arr_time,
proc[i].burst_time,proc[i].finish_time,proc[i].wait_time,proc[i].ta_time);
avg_wt+=proc[i].wait_time;
avg_ta+=proc[i].ta_time;
}
avg_wt=avg_wt/num;
avg_ta=avg_ta/num;
printf("\nAverage waiting time: %f\nAverageturn around time:
%f\n",avg_wt,avg_ta);
printganttchart(proc,num);
return 0;
}
