#include<stdio.h>
#include"queue.h"

void initQueue(Queue *queue, int size){
    queue->size = size;
    queue->rear = -1;
    queue->array = (int*) malloc(size * sizeof(int));
}

void enqueue(Queue *queue, int value) {
    queue->array[queue->rear + 1] = value;
    queue->rear = queue->rear + 1;
    queue->size = queue->size + 1;
}

int dequeue(Queue *queue) {
    int ret = queue->array[0];

    for (int i=0; i<=queue->rear; i++) {
        queue->array[i] = queue->array[i+1];
    }

    queue->rear = queue->rear - 1;
    queue->size = queue->size - 1;

    return ret;
}

void isQueueEmpty(Queue *queue){
    return queue->rear == -1;
}

void freeQueue(Queue *queue) {
    free(queue->array);
}
