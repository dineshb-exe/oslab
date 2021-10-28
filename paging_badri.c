#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
  
  srand(time(0));
    int flag = 1, temp, k = 0;
    while (flag)
    {
        temp = rand() % 16;
        for (int j = 0; j < pages; j++)
        {
            if (temp == pagetable[j][0])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            if (k == pages)
            {
                break;
            }
            pagetable[k++][0] = temp;
        }
        else
        {
            flag = 1;
        }
    }
  }
