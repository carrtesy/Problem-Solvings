#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char * filename = argv[1];
	FILE * inputfile = fopen(filename, "r");

	if (inputfile == NULL)
	{
		printf("file io error");
	}

	char person;
	int id;
	int num;
	int numgroup;

	fscanf(inputfile, "%d\n", &num);

	numgroup = (num/2)+1;
	char group[numgroup][2];
	int count[numgroup];

	for(int i = 0; i < numgroup; i++)
	{
		count[i] = 0;
	}

	while (fscanf(inputfile, "%c %d\n", &person, &id) != EOF)
	{
		int idx = id - 1;
		if (count[idx] == 0)
		{
			group[idx][0] = person;
		}
		else
		{
			group[idx][1] = person;
		}

		count[idx]++;
	} 

	for(int i = 0; i < numgroup; i++)
	{
		if(count[i] == 1)
		{
			printf("%c\n", group[i][0]);
			break;
		}
	}
}
