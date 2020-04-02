/*
	Radix Sort in C: Alternative, Better Approach

	source: https://www.acmicpc.net/problem/10989
	author: Dongmin Kim(dongmin.kim.0220@gmail.com)
*/

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int n; // number of inputs
	int limit = 10000; // number limit of the element (N, which belongs 1~ limit)
	int * arr = (int *) malloc(sizeof(int) * (limit+1)); // allocated array
	

	// 1. Get the number of input. 
	scanf("%d", &n);

	// 2. Get the elements, for n times.
	// 		increment arr[input number]
	for (int i = 0; i < n; i++)
	{
		int tmp; // variable to put the input for a while
		scanf("%d", &tmp);
		arr[tmp]++;
	}

	// 3. print the data for arr[i] times.
	for (int i = 1; i <= limit; i++)
	{
		int count = arr[i]; // variable to contain the number of occurences for each numbers		

		for (int j = 0; j < count; j++)
		{
			printf("%d\n", i);
		} 
	}
}
