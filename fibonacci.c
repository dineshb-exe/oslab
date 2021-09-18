#include<stdio.h>
    int main(){
    int n,i;
    long int a[1000];

    printf("Enter the number range:\n");
    scanf("%d",&n);
    a[0]=-1;
    a[1]=1;
    printf("FIBONACCI SERIES: \n");
    for(i=2;i<=n+1;i++){
    a[i]=(a[i-1]%10000007+a[i-2]%10000007)%10000007;
    printf(" %ld",a[i]);
    }
  return 0;
  }
