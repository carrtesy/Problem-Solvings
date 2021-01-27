#ifndef _QUEUE_H
#define _QUEUE_H

#define Data int
#define Chunk 10

typedef struct q
{
  Data * queue;
  int front;
  int end;
  int capacity;
}Queue;

// Dev Interface
void allocateQueue(Queue * q);
void initQueue(Queue * q);
void checkQueue(Queue * q);

// User Interface
Data front(Queue * q);
void enqueue(Queue * q, Data d);
Data dequeue(Queue * q);
Data isEmpty(Queue * q);
Data isFull(Queue * q);

#endif
