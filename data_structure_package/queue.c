#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Dev Interface
void allocateQueue(Queue * q)
{
  int len = q->end - q->front;
  int cap = q->capacity;
  if(len < cap) return;
  else if(len >= cap)
  {
    printf("realloc called. %d -> %d\n", cap, cap+Chunk);
    q->queue = (Data *) realloc(q->queue, (cap + Chunk)*sizeof(Data));
    q->capacity += Chunk;
  }
}

void initQueue(Queue * q)
{
  q->queue = (Data * )malloc(sizeof(Data) * Chunk);
  q->front = 0;
  q->end = 0;
  q->capacity = Chunk;
}

void checkQueue(Queue * q)
{
  int len = q->end - q->front;

  for(int i = 0; i < len; i++)
  {
    if(i % Chunk == 0) printf("\n Chunk %d: ", (i/Chunk) * Chunk + Chunk);
    printf("%d ", q->queue[i]);
  }
  printf("\n");
}

// User Interface
Data front(Queue * q)
{
  return q->queue[0];
}

void enqueue(Queue * q, Data d)
{
  int idx = q->end - q->front; 
  q->queue[idx] = d;
  q->end++;
  allocateQueue(q);
}

Data dequeue(Queue * q)
{
  if(isEmpty(q)) exit(1);

  Data dequeued_data = front(q);
  Data * tmp = q->queue;
  Data * new_addr = &tmp[1];

  q->front++;
  free(q->queue);
  new_addr = (Data *)malloc(sizeof(Data) * q->capacity);
  q->queue = new_addr;

  return dequeued_data;
}

Data isEmpty(Queue * q)
{
  return q->front == q->end;
}

Data isFull(Queue * q)
{
  return (q->end - q->front) >= q->capacity;
}

int main(void)
{
  Queue Q;
  Queue * q = &Q;

  initQueue(q);
  
  printf("enqueue from 1 to 100\n");
  for(int i=1; i<=100; i++)
  {
    enqueue(q, i);
  }

  printf("Check Current Status. \n");
  checkQueue(q);

  printf("dequeue 47 items\n");
  for(int i=1; i<=47; i++)
  {
    dequeue(q);
  }

  printf("Check Current Status. \n");
  checkQueue(q);

  free(q->queue);
}

