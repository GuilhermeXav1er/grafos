#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue{
    int size;
    int rear;
    int *array;
} Queue;

void initQueue(Queue *queue, int size);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue);
void freeQueue(Queue *queue);
void isQueueEmpty(Queue *queue);

#endif