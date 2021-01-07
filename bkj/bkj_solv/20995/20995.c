#include <stdio.h>
#include <stdlib.h>

typedef struct d{
    int value;
    int idx;
} data;

typedef struct stack{
    data* arr;
    int curlen;
    int maxlen;
} Stack;

int init(Stack * s, int m){
    s->arr = (data*)malloc(sizeof(data)*m);
    s->curlen = 0;
    s->maxlen = m;
    return 0;
}

int push(Stack * s, data n){
    if (s->curlen == s->maxlen) {
        return -1;
    } else {
        s->arr[s->curlen++] = n; 
        return 0;  
    }
}

data pop(Stack * s){
    if (!s->curlen) {
        data dummy = {-1, -1};
        return dummy;  
    } else {
        return s->arr[(s->curlen--)-1];
    }
}

data top(Stack * s){
    return s->arr[s->curlen-1];
}

int empty(Stack * s){
    return s->curlen == 0;
}

int main(void){
    int N;
    int * input;
    int * answer;
    Stack st;
    Stack * s = &st;
    
    // get input
    scanf("%d", &N);
    input = (int*)malloc(N * sizeof(int));
    answer = (int*)malloc(N * sizeof(int));
    init(s, N);

    for(int i = 0; i < N; i++){
        scanf("%d", &input[i]);
    }

    for(int i = 0; i < N; i++){
        int curval = input[i];
        
        if(empty(s)){
            answer[i] = 0;
        } else{
            while(!empty(s) && top(s).value < curval){
                pop(s);
            }

            if(empty(s)){
                answer[i] = 0;
            } else {
                answer[i] = top(s).idx;
            }
        }
        data to_push = {curval, i+1};
        push(s, to_push);
    }

    for(int i = 0; i < N; i++){
        printf("%d ", answer[i]);
    }
}
