/*
	source: https://www.acmicpc.net/problem/15652
	author: Dongmin Kim(dongmin.kim.0220@gmail.com
*/
#define Data pair

#include <stdio.h>
#include <stdlib.h>


// define data structure "pair"
// (digit, value)
typedef struct p
{
	int digit;
	int value;
} pair;


// define Stack
typedef struct s
{
	Data st[100];
	int len;
} Stack;

void initStack(Stack * s)
{
	s->len = 0;
}

void push(Stack * s, Data d)
{
	s->st[(s->len)++] = d;
}

void pop(Stack * s)
{
	s->len--;
}

int empty(Stack * s)
{
	return (s->len == 0);
}

Data top(Stack * s)
{
	if(empty(s)) exit(1);
	return s->st[(s->len)-1];
}

// utility function to print array
void printArr(Data * arr, int digit)
{
	for(int i = 1; i <= digit; i++)
	{
		printf("%d ", arr[i].value);
	}

	printf("\n");
}


int main(void)
{
	int N, M;
	Data * arr; // array to store the answers

	scanf("%d %d", &N, &M);

	arr = (Data *) malloc(sizeof(Data) * (M+1));
	
	Stack st;
	Stack * s = &st;	
	int topDigit; // identify the terminal of the loop

	initStack(s);

	// 1. initial setting
	for(int i = N; i>=1; i--)
	{
		Data tmp = {1, i};
		push(s, tmp);		
	}
	
	Data tmpTop = {top(s).digit, top(s).value};
	arr[top(s).digit] = tmpTop;



	// 2. loop until terminated
	while(!empty(s))
	{
			// 2-1. push to the stack
			while(top(s).digit != M)
			{
				int digit = top(s).digit + 1; // next digit
				int limit = top(s).value; 		// next digit's minimum

				// push the data in a reverse order
				// from N to limit
				for(int i = N; i>=limit; i--)
				{
					Data tmp = {digit, i};
					push(s, tmp);
				}

				// memorize the result to array
				Data tmpTop = {top(s).digit, top(s).value};
				arr[top(s).digit] = tmpTop;

			}

			// Print the Data
			// pop until digit is changed
			topDigit = top(s).digit; 
			while(top(s).digit == topDigit)
			{
				printArr(arr, M);
				pop(s);
				Data tmp = {top(s).digit, top(s).value};
				arr[top(s).digit] = tmp;
			}
			
			// Pop until there is no digit change
			while(1)
			{
				topDigit = top(s).digit;
				pop(s);

				Data tmpTop = {top(s).digit, top(s).value};
				arr[top(s).digit] = tmpTop;

				if(topDigit == top(s).digit) break;	
			}
			
	}

}
