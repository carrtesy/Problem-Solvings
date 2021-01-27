#include "stack.h"

// Dev Interface
void allocateStack(Stack * s)
{
  int len = s->len;
  int num_to_alloc = (len / Chunk) * Chunk + Chunk; // if Chunk is 100, 0~99 : 100, 100~200 : 200, so on. 
  
  if(num_to_alloc == s->capacity) return;
  else if(num_to_alloc >= s->capacity) // when we have to increase capacity 
  {
    printf("realloc called : %d -> %d. (Capacity Increased)\n", s->capacity, num_to_alloc);
    s->stack = (Data *)realloc(s->stack, sizeof(Data) * num_to_alloc);
    s->capacity = num_to_alloc;
  }
	else return;
}

void initStack(Stack * s)
{
  s->stack = (Data*)malloc(sizeof(Data) * Chunk);
  s->len = 0;
  s->capacity = Chunk;
}

void checkStack(Stack * s)
{
  int len = s->len;
  for (int i = 0; i < len; i++)
  {
    if (i % Chunk == 0 ) 
    {
      printf("\nChunk %d :", (i / Chunk) * Chunk + Chunk);
    } 
    printf("%d ", s->stack[i]);
  }
  printf("\n");
}

// User Interface
Data top(Stack * s)
{
  return s->stack[(s->len)-1];
}

Data pop(Stack * s)
{
  if(isEmpty(s)){
    printf("Stack is now empty. Nothing left to pop. exit.\n");
    exit(1);
  }
  Data popedData = top(s);
  s->len--;
  return popedData;
}

void push(Stack * s, Data d)
{
  s->stack[s->len++] = d;
  allocateStack(s);
}


int isEmpty(Stack * s)
{
  return s->len == 0;
}

int isFull(Stack * s)
{
  return s->len >= s->capacity; // if capacity is 100, isFull returns true from 100.
}

void showStackInfo()
{
  Stack st;
  Stack * s = &st;

  printf("This is how to INIT Stack...\n");
  printf("Let's set Stack st, and Stack * s = &st; \n");
  printf("Call by function *initStack()*\n");
  initStack(s);

  printf("This is how to push data to the stack...\n");
  printf("we can push by calling function *push(s, i)*\n");
  printf("Let's Pushing 1 to 100...\n");
  for(int i = 1; i <= 100; i++)
  {
    push(s, i);
  }
  printf("\n");


  printf("This is how to check the data of the stack...\n");
  printf("we can check by calling function *checkStack(s)*\n");
  printf("Let's print 1-100\n");
  checkStack(s);
  printf("\n");


  printf("This is how to pop the data of the stack...\n");
  printf("we can pop by calling function *pop(s)*\n");
  printf("Let's pop 47 times... \n");
  for(int i = 1; i <= 47; i++)
  {
    pop(s);
  }
  printf("\n");

  printf("which one is located at the top? use *top(s)*.\n");
  printf("Data on top is %d\n", top(s));

  printf("printing after poping...\n");
  checkStack(s);
  printf("\n");

  printf("poping until empty...\n");
  while(!isEmpty(s))
  {
    pop(s);
  }

  printf("Is Stack Empty? Check *isEmpty(s)* function. %d\n", isEmpty(s));

  printf("Let's Try poping for empty stack.\n");
  pop(s);

  free(s->stack);

}


