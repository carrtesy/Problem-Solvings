/*
	Radix sort in C

	Source: https://www.acmicpc.net/problem/10989
	Author: Dongmin Kim(dongmin.kim.0220@gmail.com) 

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
	1. Queue data structure
*/

typedef struct n{
	int data;
	struct n * next;
} Node;

typedef struct q{
	Node * head;
	int len;
} Queue;

void init(Queue * q)
{
	q->head = (Node *)malloc(sizeof(Node));
	q->head->next = NULL;
	q->len = 0;
}

void end(Queue * q)
{
	Node * cur = q->head;
	Node * nextNode;
	while(cur->next != NULL){
		nextNode = cur->next;
		free(cur);
		cur = nextNode;
	}
}

int size(Queue * q)
{
	return q->len;
}

int empty(Queue * q)
{
	return q->len == 0;
}

int front(Queue * q)
{
	if(empty(q)) return -1;
	else return q->head->next->data;
}

int back(Queue * q)
{

	if(empty(q)){
		return -1;
	} else {
		Node * cur = q->head;
		while(cur->next != NULL) cur = cur->next;

		return cur->data;
	}
		
}

void push(Queue * q, int x)
{
	//prepare new node	
	Node * nn = (Node *)malloc(sizeof(Node));
	nn->data = x;
	nn->next = NULL;

	//go to the last node
	Node * cur = q->head;

	while(cur->next != NULL) cur = cur->next;
	
	//assign next node
	cur->next = nn;
	q->len++;
}

int pop(Queue * q)
{
	if(empty(q)){
		return -1;
	} else {

		Node * cur = q->head->next;
		Node * nextNode = cur->next;
		int num = cur->data; 

		q->head->next = nextNode;
		free(cur);
		q->len--;

		return num;
	}
}


/*
	Radix Sort
*/
void radixSort(int n, int * d, int max)
{
	
	int digitLimit = (int)log10(max);

	for(int digit = 0; digit < digitLimit; digit++)
	{

			Queue bucket[10];
			// 1. initialize
			for (int i = 0; i < 10; i++) init(&bucket[i]);

			// 2. sort according to last digit			
			for(int i = 0; i < n; i++)
			{
				int x = d[i] / pow(10, digit);
				int pos = x % 10;
				push(&bucket[pos], d[i]);
			}
			

			// 3. pop 
			int idx = 0;
			for(int i = 0; i < 10; i++)
			{
				while(!empty(&bucket[i]))
				{
					d[idx++] = front(&bucket[i]);
					pop(&bucket[i]); 
				}
			}

			// 4. initialize
			for (int i = 0; i < 10; i++) end(&bucket[i]);
			
	}

}


int main(void)
{

	// 1. initial setup
	int n;
	int * arr;

	// 2. get parameter
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);	

	// 3. get data
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	// 4. sort
	radixSort(n, arr, 10000);

	// 5. print result
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
}
