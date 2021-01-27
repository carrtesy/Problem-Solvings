/*
Sorting Algorithms in C++

Author: Dongmin Kim (dongmin.kim.0220@gmail.com)
Date  : Since 2019-12-15

*/


#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>
#include <queue> // for radixsort
#include <cmath> // for radixsort

using namespace std;

/*
	Helper functions
*/

void printArr(int n, int * d)
{
	for (int i = 0; i< n; i++)
	{
		printf("%d ", d[i]);
	}
	printf("\n");
}

/*
	Type 1:
	n square algorithms
*/

void bubbleSort(int n, int *d)
{
	int tmp;
	
	for (int i = n-1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if(d[j] > d[j+1])
			{				
				tmp = d[j];
				d[j] = d[j+1];
				d[j+1] = tmp;
			}
		}
	}
}

void insertionSort(int n, int *d)
{
	int eval; // value to evaluate position	
	for (int i = 1; i < n; i++)
	{
		eval = d[i];
		for (int j = i-1; j >= 0; j++)
		{
			if(d[j] > eval) // push right if smaller
			{
				d[j+1] = d[j];
			}
			else
			{
				d[j] = eval;
				break;
			}
		}
	}
}

/*
	Type 2:
	nlogn algorithms
*/

//2-1 mergesort
void _merge(int n, int *d, int start, int mid, int end)
{
	int p, q, cur;
	int copyArr[end-start+1];
	p = start;
	q = mid+1;
	cur = 0;

	while(p <= mid && q <= end)
	{
		if (d[p] < d[q]){
			copyArr[cur++] = d[p++];
		} else {
			copyArr[cur++] = d[q++];
		}
	}

	while(p <= mid)
	{
		copyArr[cur++] = d[p++];
	}

	while(q <= end)
	{
		copyArr[cur++] = d[q++];
	}
	
	for(int i = start; i <= end; i++)
	{
		d[i] = copyArr[i-start];
	}
}

void mergeSort(int n, int * d, int start, int end)
{
	int threshold = 0;
	int mid = (start+end)/2;
	
	if(end-start > threshold)
	{
		mergeSort(n, d, start, mid);
		mergeSort(n, d, mid+1, end);
		_merge(n, d, start, mid, end);
	}

}

/*
	Type 3: Linear Style
*/

void radixSort(int n, int * d, int start, int end, int max)
{
	queue<int> bucket[10];
	int digitLimit = (int)log10(max);

	for(int digit = 0; digit < digitLimit; digit++)
	{

			// 1. sort according to last digit			
			for(int i = 0; i < n; i++)
			{
				int x = d[i] / pow(10, digit);
				int pos = x % 10;
				bucket[pos].push(d[i]);
			}
			

			// 2. pop 
			int idx = 0;
			for(int i = 0; i < 10; i++)
			{
				while(!bucket[i].empty())
				{
					d[idx++] = bucket[i].front();
					bucket[i].pop(); 
				}
			}
			
			printArr(n, d);			
	}

}

int main(void)
{
	
	int arr[13] = {5, 7, 12, 19, 21, 26, 33, 40, 14, 9, 18, 21, 2};
	int arrlen = sizeof(arr)/sizeof(int); 
	printArr(arrlen, arr);
	
	radixSort(arrlen, arr, 0, arrlen-1, 100);
	printArr(arrlen, arr);
	
}
