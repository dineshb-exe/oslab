#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
//Just a small change
int main(){
	int pr1=fork();
	wait(NULL);
	int pr2=-1;
	int pr3=-1;
	if(pr1==0){
		int n=1;
		printf("Enter the number: \n");
		scanf("%d",&n);
		if(n%2==0){
			printf("%d is even\n\n",n);
		}
		else{
			printf("%d is odd\n\n",n);
		}
	//	sleep(15);
		exit(0);
	}

	if(getpid()!=0){
		pr2=fork();
		wait(NULL);
	}
	if(pr2==0){
		int a=0;
		int b=1;
		int n=1;
		printf("Enter the number of terms you want in the series \n\n");
		scanf("%d",&n);
		if(n==0)
			printf("No term to display\n ");
		else if(n==1){
			printf("%d",a);
		}
		else if(n==2){
			printf("Fibonacci Series: %d %d\n",a,b);
		}
		else if(n>2){
			printf("Fibonacci Series: %d %d ",a,b);
			int temp=0;
			int i=2;
			while(i<n){
				temp=a+b;
				printf("%d ",temp);
				i++;
				a=b;
				b=temp;
			}
			printf("\n");
		}
		exit(0);
	}
	if(getpid()!=0){
		pr3=fork();
		wait(NULL);
	}
	if(pr3==0){
		int n=1;
		printf("Enter the number for which factorial is to be computed: \n\n\n");
		scanf("%d",&n);
		int i=1;
		long int fact=1;
		while(i<=n){
			fact=fact*i;
			i++;
		}
		printf("%ld is the factorial of %d\n\n\n",fact,n);
		exit(0);
	}
}
