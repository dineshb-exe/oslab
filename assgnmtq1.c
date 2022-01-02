#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  execl("/bin/chmod","chmod","0444","sample3.txt",NULL);//To remove write permissions of a file
  return 0;
}
