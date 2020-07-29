/*
	Implementaion of Stack in C

	source: https://www.acmicpc.net/problem/10828
	author: Dongmin Kim(dongmin.kim.0220@gmail.com)


*/

#include <stdio.h>
#include <string.h>

typedef struct s{
	int data[10000];
	int len;
} stack;

void _initStack(stack * s)
{
	s->len = 0;
}

void push(int x, stack * s)
{
	s->data[(s->len)++] = x;
}

void pop(stack * s)
{
	if(empty(s)) {
		printf("-1\n");
	} else{
		printf("%d\n", s->data[(s->len)-1]);
		s->len--;
	}
}

int size(stack * s)
{
	return s->len;
}

int empty(stack * s)
{
	return (s->len) == 0;
}

int top(stack * s)
{
	if (empty(s)) return -1;
	else return s->data[(s->len)-1]; 
}

int main(void)
{
	int n;

	stack st;
	stack * s = &st;
	_initStack(s);

	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++)
	{
		char str[20];
		gets(str);
		
		if(strncmp(str, "pop", 3) == 0){
			pop(s);
		} else if(strncmp(str, "push", 4) == 0){
			char * num_p = str+5;
			int num = atoi(num_p);
			push(num, s);
		} else if(strncmp(str, "size", 4) == 0){
			printf("%d\n", size(s));
		} else if(strncmp(str, "empty", 5) == 0){
			printf("%d\n", empty(s));
		} else if(strncmp(str, "top", 3) == 0){
			printf("%d\n", top(s));
		} 
				
	}

}
