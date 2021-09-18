#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main(int argc,char *argv[])
{
int i,fd,fd1,r;
char buf[50];
if(argc<2)
{
printf("mycat:Too few arguments!**!");
return 0;
}
else if(argc>2)
{
if(!strcmp(argv[1],">"))
{
fd=creat(argv[2],00777);
while((r=read(0,buf,50))>0)
write(fd,buf,r);
return 0;
}
else if(!strcmp(argv[2],">"))
{
fd=open(argv[1],0,00777);
if(fd==-1)
{
printf("mycat:%s:No such file or directory!**!\n",argv[1]);
return 0;
}
fd1=creat(argv[3],00777);
while((r=read(fd,buf,50))>0)
write(fd1,buf,r);
return 0;
}
else if(!strcmp(argv[2],">>"))
{
fd=open(argv[1],O_RDWR);
fd1=open(argv[3],O_RDWR|O_APPEND);
if(fd==-1)
{
printf("error");
return 1;
}
if(fd1==-1)
fd=creat(argv[3],00777);
while((r=read(fd,buf,50))>0)
write(fd1,buf,r);
return 0;
}
else
{
for(i=1;i<argc;i++)
{
fd=open(argv[i],O_RDWR);
if(fd==-1)
printf("mycat:%s:No such file or directory!**!\n",argv[i]);
else
while((r=read(fd,buf,50))>0)
write(1,buf,r);
}
}
}
else
{
fd=open(argv[1],0,O_RDWR);
if(fd==-1)
printf("mycat:%s:No such file or directory!**!\n",argv[1]);
else
while((r=read(fd,buf,50))>0)
write(1,buf,r);
}
return 0;
}
