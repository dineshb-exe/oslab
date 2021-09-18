#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<time.h>
void sfile(char const filename[]);
int main()
{
ssize_t read;
char* buffer=0;
size_tbuf_size=0;
printf("Enter filename: ");
read=getline(&buffer,&buf_size,stdin);
if(read<=0)
{
printf("Getline failed\n");
exit(1);
}
if(buffer[read-1]=='\n')
buffer[read-1]=0;
int s=open(buffer,O_RDONLY);
if(s==-1)
{
printf("File doesn't exists\n");
exit(1);
}
else
{
sfile(buffer);
}
free(buffer);
return 0;
}
void sfile(char const filename[])
{
struct stat sfile;
if(stat(filename,&sfile)==-1)
{
printf("Error Occured ! \n");
}
printf("\nFile : %s",filename);
printf("\nSize: %ld ",sfile.st_size);
printf("\t\tBlocks: %ld",sfile.st_blocks);
printf("\t\tIO Block: %ld",sfile.st_blksize);
printf("\nDevice: %ldh" ,sfile.st_dev);
printf("\tInode: %ld",sfile.st_ino);
printf("\tLink: %u",(unsigned int)sfile.st_nlink);
printf("\nUid: %d",sfile.st_uid);
printf("\tGid: %d",sfile.st_gid);
printf("\nAccess: \nUser: ");
printf((sfile.st_mode& S_IRUSR)?"r":"-");
printf((sfile.st_mode& S_IWUSR)?"w":"-");
printf((sfile.st_mode& S_IXUSR)?"x":"-");
printf("\nGroup: ");
printf((sfile.st_mode& S_IRGRP)?"r":"-");
printf((sfile.st_mode& S_IWGRP)?"w":"-");
printf((sfile.st_mode& S_IXGRP)?"x":"-");
printf("\nOthers: ");
printf((sfile.st_mode& S_IROTH)?"r":"-");
printf((sfile.st_mode& S_IWOTH)?"w":"-");
printf((sfile.st_mode& S_IXOTH)?"x":"-");
printf("\nAccess: %s",ctime(&sfile.st_atime));
printf("Modify: %s",ctime(&sfile.st_mtime));
printf("Change: %s",ctime(&sfile.st_ctime));
}
