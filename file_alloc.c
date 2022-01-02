#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

void file_alloc(bool* files){
  int startpos,flag=0,i,k,ch,b_size;
  printf("Enter the starting index of the block and the length of the block to be allocated: ");
  scanf("%d %d",&startpos,&b_size);
  for(i=startpos;i<(startpos+b_size);i++){
    if(files[i]==0)
    flag++;
  }
  if(b_size==flag){
    k=startpos;
    memset((files+k),1,sizeof(bool)*b_size);
    if(k+b_size!=(startpos+b_size-1)){
      printf("The file has been allocated successfully\n");
    }
  }
  else{
    printf("File can't be allocated in the said position\n");
  }
  printf("Do you want to enter more files?\n");
    printf("Press 1 for YES, 0 for NO: ");
    scanf("%d", &ch);
    if (ch == 1)
        file_alloc(files);
    else
        exit(0);
    return;
}

int main(int argc, char const *argv[]) {
  /* code */
  bool* files;
  int n;
  sscanf(argv[1],"%d",&n);
  files = (bool *)calloc(n,sizeof(bool));
  memset(files,0,sizeof(bool)*n);
  file_alloc(files);
  return 0;
}
