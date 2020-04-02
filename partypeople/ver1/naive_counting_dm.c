#include <stdio.h>

int main(void)
{
  int max = -1;
  int n = 200001;
  int numbers = (int *) malloc(sizeof(int) * n);
  int tmp;

  for(int i = 0; i < n; i++)
  {
    scanf("%d", &numbers[i]);
  }
  

  //get max
  for(int i = 0; i < n; i++)
  {
    tmp = numbers[i];
    if(tmp > max) max = tmp;
  }

  int * storage = (int*) malloc(sizeof(int)*max);
  for:

}
