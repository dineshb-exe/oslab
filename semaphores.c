//2-types binary sempaphors and counting sempaphors
//2 functions wait() and signal()
//Bounded buffer also called producer and consumer processes
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int ch,counter=0,b_size;
  printf("Enter the buffer size: ");
  scanf("%d", &b_size);
  printf("Enter 1 to produce:\nEnter 2 to consume: \nEnter 3 to exit: \n");
  scanf("%d", &ch);
  int item=1;
  int ic=1;
  while (ch!=3) {
    /* code */
    if(ch==1){
      printf("Producer: ");
      if(counter==b_size){
        printf("Buffer Full\n");
      }
      else{
        printf("produces item %d\n", item);
        counter++;
        item++;
      }
    }
    else if(ch==2){
      printf("Consumer: ");
      if(counter==0){
        printf("Buffer Empty\n");
      }
      else{
        printf("consumes item %d \n",ic );
        counter--;
        ic++;
      }
    }
    else if(ch>3||ch<3){
      printf("Invalid Input\n" );
    }
    scanf("%d", &ch);
  }
  return 0;
}
