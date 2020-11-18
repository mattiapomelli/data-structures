#ifndef QUEUE_H
#define QUEUE_H

typedef struct queue *Queue;

Queue newQueue(int size);

int size(Queue pt);

int isEmpty(Queue pt);

int front(Queue pt);

void enqueue(Queue q, int x);

void dequeue(Queue q);

void printQueue(Queue q);

#endif