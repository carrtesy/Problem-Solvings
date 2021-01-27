#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

#define Data int
#define Chunk 10

typedef struct s 
{
  Data * stack;
  int len; // amount of data stored
  int capacity; // amount of available data to be stored
} Stack; 

// Dev Interface
void allocateStack(Stack * s);
void initStack(Stack * s);
void checkStack(Stack * s);

// User Interface
Data pop(Stack * s);
Data top(Stack * s);
void push(Stack * s, Data d);
int isEmpty(Stack * s);
int isFull(Stack * s);
void showStackInfo();

#endif
