#include<stdio.h>

int main()
{
	int n=20;
	//printf("\nEnter the number of page references: ");
	int pages[]={1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	//printf("\nEnter the page numbers: ");
	int i=0;
	//for(i=0;i<n;i++)
	//{
	//	printf("\nReference %d:",i); scanf("%d",&pages[i]);
	//}
	int framesize=4;
	//scanf("\nEnter the number of frames: "); scanf("%d",&frames);
	int frames[framesize];
	int miss=framesize,hit=0;
	for(i=0;i<framesize;i++)
	{
		frames[i] = pages[i];
	}
	for(i=framesize;i<n;i++)
	{
		int j,flag=0;
		for(j=0;j<framesize;j++)
		{
			if(pages[i] == frames[j])
				flag=1;
		}
		if(flag==1)
		{
			hit++;
		}
		else
		{
			miss++;	
		}
	}
	printf("\nNo. of Page faults = %d",miss);
	printf("\nNo. of hits = %d",hit);
	printf("\n");
}
