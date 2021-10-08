#include<stdio.h>

const int M=3;
const int N=5;

int finished(int f[N]){
  if(f[0]==1&&f[1]==1&&f[2]==1&&f[3]==1&&f[4]==1)
    return 1;
  else
    return 0;
}
int main(int argc, char const *argv[]) {
  int max[N][M],available[M],need[N][M],allocation[N][M];
  printf("Enter the instances of all the resoures: \n");
  for(int i=0;i<M;i++){
    scanf("%d",&available[i]);
  }
  int sum_al[M];
  for(int i=0;i<M;i++){
    sum_al[i]=0;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      printf("Enter the maximum instances of resource %d requested by process %d ",j,i);
      scanf("%d",&max[i][j]);

    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      printf("Enter the instances of resource %d allocated to process %d ",j,i);
      scanf("%d",&allocation[i][j]);
    }
  }
  printf("Need table of the processes:\n");
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      need[i][j]=max[i][j]-allocation[i][j];
      printf("%d\t",need[i][j]);
    }
    printf("\n");
  }
  printf("Available:\n");
  int work[M];
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      sum_al[i]=sum_al[i]+allocation[j][i];
    }
    available[i]=available[i]-sum_al[i];
    work[i]=available[i];
    printf("%d\t", available[i]);
  }
  printf("\n");
  int finish[N];
  for(int i=0;i<N;i++){
    finish[i]=0;
  }
  int safe_seq[N];
  for(int i=0;i<N;i++){
    safe_seq[i]=0;
  }
  int sc=0;
  int i=0;
  while(!finished(finish)){
    if(finish[i]==0){
      int ch=1;
      for(int j=0;j<M&&ch==1;j++){
        if(need[i][j]>work[j])
        ch=0;
      }
      if(ch==1){
        for(int k=0;k<M;k++){
          work[k]=work[k]+allocation[i][k];
        }
        safe_seq[sc++]=i;
        finish[i]=1;
      }
      i=(i+1)%N;
    }
    else{
      i=(i+1)%N;
    }
  }
  printf("Safe Sequence: \n");
  for(int l=0;l<N;l++){
    printf("P%d\t", safe_seq[l]);
  }
  printf("\n");
  return 0;
}
