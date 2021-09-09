#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

void lsssimul1(const char* path){
  struct dirent *temp;
  DIR* dp=opendir(path);
  if(dp==NULL){
    return;
  }
  temp=readdir(dp);
  while(temp!=NULL){
    if(strcmp(temp->d_name,".")!=0&&strcmp(temp->d_name,"..")!=0){
      printf("%s\n",temp->d_name);
      char npath[1000];
      strcpy(npath,path);
      strcat(npath,"\");
      strcat(npath,temp->d_name);
      lsssimul1(npath);
    }
  }
  closedir(dp);
}

int main(){
  char path[1000];
  printf("Enter the current path: ");
  scanf(" %[^\n]",path);
  lsssimul1(path);
}
