/*
	source: https://www.acmicpc.net/problem/1992
	author: Dongmin Kim (dongmin.kim.0220@gmail.com)
*/

#include <stdio.h>
#include <stdlib.h>

int arrIsClean(int** arr, int row, int col, int arrDim)
{
	// get arr,
	// top-left coordinate (x, y)
	// Dimension of array
	int firstValue = arr[row][col];

	for (int i = row; i < row+arrDim; i++)
	{
		for (int j = col; j < col+arrDim; j++)
		{
			if(arr[i][j] != firstValue)
			{
				return 0;
			}
		}
	} 

	return 1;
}

void quadZip(int** arr, int row, int col, int arrDim)
{
	
	if(arrIsClean(arr, row, col, arrDim))
	{
		// check if array is clean: terminal condition
		printf("%d", arr[row][col]);
	}
	else
	{
		int nextArrDim = arrDim/2;
		printf("(");
		quadZip(arr, row, col, nextArrDim);	// top-left
		quadZip(arr, row, col+nextArrDim, nextArrDim); // top-right
		quadZip(arr, row+nextArrDim, col, nextArrDim); // bottom-left
		quadZip(arr, row+nextArrDim, col+nextArrDim, nextArrDim); //bottom-right
		printf(")");
	}
}

int main(void)
{
	int N;

	// 1. get input
	scanf("%d", &N);

	int** inputArr = (int**)malloc(sizeof(int *) * N);

	
	for(int i = 0; i< N; i++)
	{
		char tmp[N*2+1];
		
		inputArr[i] = (int*)malloc(sizeof(int)*N);
		scanf("%s", &tmp);
 
		for(int j = 0; j< N; j++)
		{
			inputArr[i][j] = (tmp[j] == '0')? 0 : 1;
		}
	}

	// 2. call quadtree
	quadZip(inputArr, 0, 0, N);


	// 3. terminate
	printf("\n");
	for(int i = 0; i<N; i++)
	{
		free(inputArr[i]);
	}
	free(inputArr);
}

