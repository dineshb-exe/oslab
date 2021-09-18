#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<string.h>

void utility(char *pwd,int x)
{
    DIR *gg;
    struct dirent *finfo;
    gg=opendir(pwd);
    if(gg==NULL)
    {
      return;
    }
    while((finfo=readdir(gg))!=NULL)
    {
      for(int i=0;i<x;i++)printf("*");
      char *temp=finfo->d_name;
      if((strcmp(".",temp))==0 || (strcmp("..",temp))==0);
      else
      {
        printf("%s\n",finfo->d_name);
        char op[10000] = "./" ;
        strcpy(op,pwd);
        strcat(op,"/");
        strcat(op,temp);
        utility(op,x+1);
      }
    }
    closedir(gg);
}


void main(int argc,char **argv)
{
  if(argc==2)
    utility(argv[1],0);
  else
    utility(".",0);
}
