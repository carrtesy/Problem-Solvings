/*
	
	Implemention of Queue in C
	source: https://www.acmicpc.net/problem/1193
	author: Dongmin Kim(dongmin.kim.0220@gmail.com)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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



int main(void)
{
	Queue queue;
	Queue * q = &queue;
	int n;
	init(q);

	//1. get inputs, and clear the buffer
	scanf("%d", &n);
	getchar();

	//2. iterate
	for (int i = 0; i < n; i++)
	{
		char str[20];
		gets(str);
		
		if(strncmp(str, "pop", 3) == 0){
			printf("%d\n",pop(q));
		} else if(strncmp(str, "push", 4) == 0){
			char * num_p = str+5;
			int num = atoi(num_p);
			push(q, num);
		} else if(strncmp(str, "size", 4) == 0){
			printf("%d\n", size(q));
		} else if(strncmp(str, "empty", 5) == 0){
			printf("%d\n", empty(q));
		} else if(strncmp(str, "front", 5) == 0){
			printf("%d\n", front(q));
		} else if(strncmp(str, "back", 4) == 0){
			printf("%d\n", back(q));
		} 
				
	}

	//3. free
	end(q);
}
