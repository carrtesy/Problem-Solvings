/*
	Implementation of Naive Counting
	by Dongmin Kim ( dongmin.kim.0220@gmail.com )
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	// 1. connect inputfile
	char * filename = argv[1];
	FILE * inputfile = fopen(filename, "r");
	
	// 2. get input
	int id, max = 0;
	char * arr; // this array stores either 0 or 1. 	

	while(1)
	{
		// break condition: end of file
		if(fscanf(inputfile, "%d\n", &id) == EOF) break;

		// init check: if it is the first time for the loop, allocate.
		if (max == 0) arr = (char *) malloc(sizeof(char) * (id+1));

		// max check: if max value is updated, reallocate array.
		if (id > max)
		{
			arr = (char*)realloc(arr, (sizeof(char) * (id+1)));
			printf("%d bytes Memory allocated.\n", id+1);
			max = id;
		}

		arr[id] = !arr[id]; // 1 for odd time, 0 for even time (0 or 2)
	}

	for (int i = 1; i <= max; i++)
	{
		if(arr[i]) printf("answer: %d\n", i);
	}

	printf("memory used: %ld bytes\n", sizeof(char) * (max+1)); 
	free(arr);
}
