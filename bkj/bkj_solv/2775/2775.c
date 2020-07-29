/*
	source: https://www.acmicpc.net/problem/2775
	author: Dongmin Kim(dongmin.kim.0220@gmail.com)

*/

#include <stdio.h>
#include <stdlib.h>

void print2DArr(int ** arr, int k, int n)
{
	for (int i = 0; i < k+1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	} 
}

int main(void)
{
	int T, k, n;
	
	scanf("%d", &T);
	int * sol = (int *)malloc(T* sizeof(int));

	for(int i = 0 ; i< T; i++)
	{
		scanf("%d", &k);
		scanf("%d", &n);

		// allocation
		int * arr[k+1];

		for (int j = 0; j < k+1; j++)
		{
			arr[j] = (int *)malloc(n * sizeof(int));
		}		
		
		// init 0th floor
		for (int j = 0; j < n; j++)
		{
			arr[0][j] = j+1;
		}

		// iterate from 1st floor to k-1th floor
		for (int floor = 1; floor <= k; floor++)
		{
			arr[floor][0] = 1;
			for (int room = 1; room < n; room++)
			{
				arr[floor][room] = arr[floor-1][room] + arr[floor][room-1];
			}
		}

		sol[i] = arr[k][n-1];
	}
	
	for(int i = 0; i<T; i++)
	{
		printf("%d\n", sol[i]);
	}
}
