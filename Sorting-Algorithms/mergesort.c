/*
Implementation of Merge Sort in C

source: https://www.acmicpc.net/problem/2751
author: Dongmin Kim(dongmin.kim.0220@gmail.com)

*/


#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <algorithm>


/*
	Helper functions
*/

void printArr(int n, int * d)
{
	for (int i = 0; i< n; i++)
	{
		printf("%d\n", d[i]);
	}
}


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


int main(void)
{
	int n; 
	
	scanf("%d", &n);
	int arr[n];

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	mergeSort(n, arr, 0, n-1);
	printArr(n, arr);
	
}
