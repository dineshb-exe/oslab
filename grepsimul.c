//Sri:
//Program to simulate grep -c and grep -h using C
#include<stdio.h>
#include<string.h>

void dashc(char* filename, char* pattern){
  int count=0;
  char tempstr[1000];
  FILE *fp=fopen(filename,"r");
  if(fp==NULL){
    printf("File not found\n");
    return;
  }
  while(fscanf(fp," %[^\n]",tempstr)!=EOF){
    if(strstr(tempstr,pattern)!=NULL)
    count++;
  }
  printf("%d\n",count);
  fclose(fp);
}
void dashh(char* filename,char* pattern){
  char tempstr[1000];
  FILE* fp=fopen(filename,"r");
  while(fscanf(fp," %[^\n]",tempstr)!=EOF){
    if(strstr(tempstr,pattern)!=NULL){
      printf("%s\n",tempstr);
    }
  }
  fclose(fp);
}

int main(int argc,char** argv){
  int ch=0;
  for(int i=1;i<argc&&ch==0;i++){
    if(strcmp(argv[i],"-c")==0){
      dashc(argv[i+2],argv[i+1]);
      ch=1;
    }
    else if(strcmp(argv[i],"-h")==0){
      dashh(argv[i+2],argv[i+1]);
      ch=1;
    }
  }
}
