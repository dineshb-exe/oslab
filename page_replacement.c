#include<stdio.h>
#include<stdlib.h>
#define N 20

int main(){
	int f,pf=0,hits=0;
	int page_ref_str[N];
	printf("Enter the number of frames: ");
	scanf("%d",&f);
	int tbr=0;
	printf("Enter the page-reference string: ");
	for(int i=0;i<N;i++){	
		scanf("%d",&page_ref_str[i]);
	}
	int* frames = malloc(f*sizeof(int));
	for(int i=0;i<N;i++){
		if(i<f){
			if(i==0){			
				frames[tbr] = page_ref_str[i];
				printf("Pass %d:",i+1);
				for(int j=0;j<=tbr;j++){
					printf("%d ",frames[j]);	
				}		
				tbr=(tbr+1)%f;
				pf++;
				printf("\n");
			}
			else if(i>0){
				int ch=1;			
				for(int j=0;j<tbr&&ch==1;j++){
					if(frames[j]==page_ref_str[i])
					ch=0;
				}
				if(ch==1){
					frames[tbr]=page_ref_str[i];
					printf("Pass %d:",i+1);				
					for(int k=0;k<tbr;k++){
						printf("%d ",frames[k]);	
					}				
					tbr=(tbr+1)%f;
					pf++;
							
				}
				else{
					hits++;
					printf("Pass %d:",i+1);
					for(int k=0;k<tbr;k++){
						printf("%d ",frames[k]);	
					}
				}
			}		
		}	
		else{
			int ch=1;			
			for(int j=0;j<f&&ch==1;j++){
				if(frames[j]==page_ref_str[i])
				ch=0;
			}
			if(ch==1){
				frames[tbr]=page_ref_str[i];
				printf("Pass %d:",i+1);				
				for(int k=0;k<f;k++){
					printf("%d ",frames[k]);	
				}				
				tbr=(tbr+1)%f;
				pf++;
							
			}
			else{
				hits++;
				printf("Pass %d:",i+1);
				for(int k=0;k<f;k++){
					printf("%d ",frames[k]);	
				}
			}
		}
	}
	printf("The number of page faults is %d\n",pf);
	printf("The number of hits is %d\n",hits); 
}
