#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void printganttchart(int* porder, int np, int* bursttime){
  for(int i=0;i<np;i++){
    printf("P%d",porder[i]);
    for(int j=2;j<bursttime[porder[i]];j++){
      printf("-");
    }
  }
  printf("\n");
  for(int i=0;i<np;i++){
    printf("|");
    for(int j=1;j<bursttime[porder[i]];j++){
      printf("-");
    }
  }
  printf("\n");
  int sum=0;
  for(int i=0;i<np;i++){
    printf("%d",sum);
    for(int j=2;j<bursttime[porder[i]];j++){
      printf("-");
    }
    sum+=bursttime[porder[i]];
  }
}

int main(int argc, char const *argv[]) {
  int arr[]={3,1,2,4,0};
  int bt[]={6,7,2,6,5};
  int n=5;
  printganttchart(arr,n,bt);
  return 0;
}
