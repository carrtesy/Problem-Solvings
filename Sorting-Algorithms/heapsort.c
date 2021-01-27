/*
	implementation of heapsort

	author: Dongmin Kim (dongmin.kim.0220@gmail.com)
*/

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

void printArr(int * arr, int len)
{
	printf("[ ");	
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

void pushData(int * arr, int len, MaxHeap * MH)
{
	// Heapify
	for(int i = 0; i < len; i++)
	{
		pushHeap(MH, arr[i]);
	}
}

void popAndSetData(int * arr, int len, MaxHeap * MH)
{
	// Sort
	for(int i = len-1; i >= 0; i--)
	{
		arr[i] = popHeap(MH);	
	}
}

void heapSort(int * arr, int len, MaxHeap * MH)
{
	pushData(arr, len, MH);
	popAndSetData(arr, len, MH);
} 


int main(void)
{
	int arr[5] = {3, 2, 4, 5, 1};

	MaxHeap m;
	MaxHeap * MH = &m;
	initHeap(MH);
	heapSort(arr, 5, MH);
	printArr(arr, 5);
	

}

