#include <stdio.h>

void insertionSort(int * arr, int n)
{
  int tmp, idx;

  for(int i = 1; i < n; i++)
  {
    tmp = arr[i];
    idx = i;
    for(int j = i-1; j >=0 ; j--)
    {
      if(arr[j] > tmp)
      {
        arr[j+1] = arr[j];
        idx--;
      }
      else
      {
        break;
      }
    }
    arr[idx] = tmp;
  }
}


void printArr(int * arr, int n)
{
  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");
}

int main()
{
  int arr[5] = {5,23,3,4,1};
  printArr(arr, 5);
  insertionSort(arr, 5);
  printArr(arr, 5);
}
