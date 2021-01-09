#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 2000000
typedef int Data;

typedef struct _Queue{
    Data* arr;
    int front;
    int back;
} Queue;

void init(Queue* q);
void push(Queue* q, Data d);
void pop(Queue* q);
void size(Queue* q);
int empty(Queue* q);
void front(Queue* q);
void back(Queue* q);

int main(void){
    Queue queue;
    Queue* q= &queue;
    init(q);
    int N;
    scanf("%d", &N);

    while(N--){
        char command[100];
        scanf("%s", command);

        switch (command[0]){
            case 'p':
                if (command[1] == 'u'){
                    Data number;
                    scanf("%d", &number);
                    push(q, number); 
                } else {
                    pop(q);
                }
                break;
            case 's':
                size(q);
                break;
            case 'e':
                printf("%d\n", empty(q));
                break;
            case 'f':
                front(q);
                break;
            case 'b':
                back(q);
                break;
        }
        
    }

}

void init(Queue* q){
    q->arr = (Data*)malloc(sizeof(int) * MAX_LEN);
    q->front = 0;
    q->back = 0;
}

void push(Queue* q, Data d){
    q->arr[q->back++] = d;
}

void pop(Queue* q){
    if (empty(q)){
        printf("-1\n");
        return;
    }
    printf("%d\n", q->arr[q->front++]);
}

void size(Queue* q){
    printf("%d\n", q->back - q->front);
}

int empty(Queue* q){
    return q->front == q->back;
}

void front(Queue* q){
    if (empty(q)){
        printf("-1\n");
        return;
    }
    printf("%d\n", q->arr[q->front]);
}

void back(Queue* q){
    if (empty(q)){
        printf("-1\n");
        return;
    }
    printf("%d\n", q->arr[q->back - 1]);
}

