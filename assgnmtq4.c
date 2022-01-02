#include<stdio.h>

int main(int argc, char const *argv[]) {
  int add;
  sscanf(argv[1],"%i",&add);
  printf("Page Number: %d\n",add>>12);
  printf("Page Number: %d\n",add&4095);
  return 0;
}
