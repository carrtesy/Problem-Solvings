#include <stdio.h>


void printArr(int * arr, int start, int end)
{
  for(int i = start; i <= end; i++)
    printf("%d ", arr[i]);

  printf("\n");
}

void insertionSort(int * arr, int start, int end)
{
  int tmp, idx;

  for(int i = start + 1; i <= end; i++)
  {
    tmp = arr[i];
    idx = i;
    for(int j = i-1; j >= start ; j--)
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

  printArr(arr, start, end);
}


int getPivot(int * arr, int start, int mid, int end)
{
  int a, b, c;
  a = arr[start];
  b = arr[mid];
  c = arr[end];

  // sort a b c
  if(b <= c) // a b c
    if(a <= b) // a b c
      return mid;
    else // b a c
      if(a >= c) // b c a
        return end;
      else
        return start;
  else // c<b a c b
    if(a <= c)
      return end;
    else // c a b 
      if(a <= b)
        return start;
      else
        return mid;
}

void swap(int * arr, int x, int y)
{
  int tmp;
  tmp = arr[x];
  arr[x] = arr[y];
  arr[y] = tmp;
}

int _quick(int * arr, int start, int mid, int end)
{
  int s, e;
  int pivot;
  int pivotValue;

  pivot = getPivot(arr, start, mid, end);
  pivotValue = arr[pivot];

  if(pivot == start)
    swap(arr, start, end);
  else if(pivot == mid)
    swap(arr, mid, end);
  else if(pivot == end)
    ; // do nothing

  s = start;
  e = end-1;

  while(1)
  {
    while(arr[s] <= pivotValue) s++;
    while(arr[e] >  pivotValue) e--;

    if(s > e) break;

    swap(arr, s, e);
  }

  swap(arr, s, end);

  return s;
}


void quickSort(int * arr, int start, int end)
{
  int n   = end-start+1;
  int mid = (start+end)/2;
  int next;

  printArr(arr, start, end);

  if(n < 10)
  {
    insertionSort(arr, start, end);
  }
  else
  {
    next = _quick(arr, start, mid, end);
    quickSort(arr, start, next);
    quickSort(arr, next+1, end);
  }
}


int main()
{
  int arr[25] = {13,77,49,35,61,
                 48,73,23,95,3,
                 89,37,57,99,17,
                 32,94,28,15,55,
                 7, 51,88,97,62
                };
  printArr(arr, 0, 24);
  quickSort(arr, 0, 24);
  printArr(arr, 0, 24);
}
