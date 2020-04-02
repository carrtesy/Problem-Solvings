#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// stack, queue data structure
typedef struct s{
	int * arr;
	int top;
} Stack;

typedef struct q{
	int * arr;
	int front;
	int back;
} Queue;

void initStack(Stack * s, int len);
void initQueue(Queue * q, int len);
void pushStack(Stack * s, int data);
void pushQueue(Queue * q, int data);
void popStack(Stack * s);
void popQueue(Queue * q);
int emptyStack(Stack * s);
int emptyQueue(Queue * q);
void clearStack(Stack * s);
void clearQueue(Queue * q);

// array handle module
int ** init_arr(int size);
void print_2d_arr(int ** arr, int size);
void scan_data(int ** arr, int time);
void clear_arr(int ** arr, int size);

// DFS, BFS
void DFS(int ** arr, int N, int M, int V);
void BFS(int ** arr, int N, int M, int V);


/*
Main
*/

int main(void){
	int N, M, V;
	int **arr;
	scanf("%d %d %d", &N, &M, &V);
	arr = init_arr(N);
	scan_data(arr, M);

	DFS(arr, N, M, V);
	BFS(arr, N, M, V);

	clear_arr(arr, N);
}	


// stack, queue data structure
void initStack(Stack * s, int len){
	s->arr = (int *)malloc(sizeof(int)*len);
	s->top = 0;
}

void initQueue(Queue * q, int len){
	q->arr = (int *)malloc(sizeof(int)*len);
	q->front = 0;
	q->back = 0;
}

void pushStack(Stack * s, int data){
	s->arr[(s->top)++] = data;
}

void pushQueue(Queue * q, int data){
	q->arr[(q->back)++] = data;
}

void popStack(Stack * s){
	(s->top)--;
}
void popQueue(Queue * q){
	(q->front)++;
}

int emptyStack(Stack * s){
	return s->top == 0;
}

int emptyQueue(Queue * q){
	return q->front == q->back;
}

void clearStack(Stack * s){
	free(s->arr);
}
void clearQueue(Queue * q){
	free(q->arr);
}


// array handle module
int ** init_arr(int size) {
	int ** arr = (int**)malloc(sizeof(int*) * (size+1));
	for(int i = 0; i < size+1; i++){
		arr[i] = (int*)malloc(sizeof(int)*(size+1));
		memset(arr[i], 0, size+1);
	}
	
	return arr;
}

void print_2d_arr(int ** arr, int size) {
	printf("[\n");	
	for(int i = 0; i<size+1; i++){	
		for(int j = 0; j<size+1; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}

void scan_data(int ** arr, int time){
	int v1, v2;
	for(int i = 0; i<time; i++){
		scanf("%d %d", &v1, &v2);
		arr[v1][v2] = 1;
		arr[v2][v1] = 1;
	}
}

void clear_arr(int ** arr, int size) {
	for(int i = 0; i < size+1; i++){
		free(arr[i]);
	}
	free(arr);	
}

// DFS, BFS
void DFS(int ** arr, int N, int M, int V){
	int visited[N+1]; 
	memset(visited, 0, (N+1)*4);

	Stack stack;
	Stack * s = &stack;
	initStack(s, N*N);

	pushStack(s, V);
	while(!emptyStack(s)){
		int topItem = s->arr[(s->top)-1];
		
		popStack(s);

		if(visited[topItem] == 0){
			visited[topItem] = 1;
			printf("%d ", topItem); 
		}
	
		for (int i = N; i>0; i--){
			if(arr[topItem][i] != 0 && visited[i] == 0){
				pushStack(s, i);
			}
		}

	}
	printf("\n");
	clearStack(s);
}


void BFS(int ** arr, int N, int M, int V){
	int visited[N+1];
	memset(visited, 0, (N+1) * 4);

	Queue queue;
	Queue * q = &queue;
	initQueue(q, N*N);

	pushQueue(q, V);
	while(!emptyQueue(q)){
		int frontItem = q->arr[q->front];
		popQueue(q);

		if(visited[frontItem] == 0){
			visited[frontItem] = 1;
			printf("%d ", frontItem); 
		}
	
		for (int i = 1; i<=N; i++){
			if(arr[frontItem][i] != 0 && visited[i] == 0){
				pushQueue(q, i);
			}
		}

	}
	printf("\n");
	clearQueue(q);
}

