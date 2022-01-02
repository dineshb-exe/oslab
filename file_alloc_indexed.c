#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<string.h>
#define N 31

struct File{
  char name[N];
  int size;
  int index;
  int* mem;
};

int main(int argc, char const *argv[]) {
  /* code */
  srand(time(0));
  int nb;
  printf("Enter the number of blocks: ");
  scanf("%d",&nb);
  int r=rand()%(nb+1);
  bool *bcheck=(bool* )malloc(nb*sizeof(bool));
  memset(bcheck,0,nb*sizeof(bool));
  struct File f1;
  int nrem=nb;
  int ch;
  char dummy;
  do{
    printf("Enter the name of the file: ");
    scanf("%c",&dummy);
    gets(f1.name);
    do{
      printf("Enter/Re-enter the number of blocks the file occupies: \n" );
      scanf("%d",&f1.size);
    }while(f1.size>=nrem);
    if(f1.size<nrem&&f1.size>1){
      f1.mem=(int*)malloc(f1.size*sizeof(int));
      for(int i=0;i<=f1.size;i++){
        if(i==0){
          do{
            f1.index=rand()%(nb+1);
          }while(bcheck[f1.index]==1);
          nrem--;
          bcheck[f1.index]=1;
          printf("Index is stored in block %d\n",f1.index);
        }
        else{
          do{
            f1.mem[i-1]=rand()%(nb+1);
          }while(bcheck[f1.mem[i-1]]==1);
          nrem--;
          bcheck[f1.mem[i-1]]=1;
          printf("Block %d of Data is stored in block %d\n",i,f1.mem[i-1]);
        }
      }
      printf("File has been allocated successfully\n");
    }
    else{
      perror("File can't be allocated\n");
    }
    printf("Do you want to allocate more files: \nEnter 1 for YES 0 for NO: ");
    scanf("%d",&ch);
  }
  while(ch==1&&nrem>0);
  if(ch==1){
    printf("All the blocks are filled with files\n");
  }
  free(f1.mem);
  return 0;
}
