#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

struct page_table{
  int frameno;
  int address;
  int flag;
};

int main(){
  srand(time(NULL));
  int f,fsize,pages,stadd;
  printf("Enter the number of frames: ");
  scanf("%d", &f);//16
  printf("Enter the frame size: ");
  scanf("%d", &fsize);//4
  printf("Enter the number of pages: ");
  scanf("%d", &pages);//5
  printf("Enter the starting address: ");
  scanf("%d", &stadd);//5000
  struct page_table* p1 = (struct page_table* ) malloc(sizeof(struct page_table)*pages);
  for(int i=0;i<pages;i++){
    p1[i].frameno=-1;
    p1[i].flag=0;
    if(i==0){
      p1[i].address=stadd;
    }
    else{
      p1[i].address=stadd+(i*fsize);
    }
  }
  int ch;
  for(int i=0;i<pages;i++){
    do{
      int pf=rand()%16;
      ch=1;
      p1[i].frameno=pf;
      if(i>0){
        for(int j=i-1;j<i;j++){
          if(p1[j].flag==1&&p1[j].frameno==p1[i].frameno){
            ch=0;
          }
        }
      }
    }while(ch!=1);
    p1[i].flag=1;
  }
  for(int i=0;i<pages;i++){
    printf("Page: %d  | Frame: %d  | Address: %d",i,p1[i].frameno,p1[i].address);
    printf("\n");
  }
  int pno,psiz;
  do{
    printf("Enter a valid page number: ");
    scanf("%d",&pno);
    if(pno>pages-1||pno<0)
    perror("Invalid Page\n");
  }while (pno>pages-1||pno<0);
  do{
    printf("Enter an offset: ");
    scanf("%d", &psiz);
    if(psiz>fsize||psiz<0)
    perror("Invalid Offset\n");
  }while(psiz<0||psiz>fsize);
  printf("The physical address: %d\n", stadd+(pno*fsize)+psiz);
}
