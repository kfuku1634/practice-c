#include <stdlib.h>

typedef struct MyQueue {
    int j;
    int size;
    int capacity;
    int *data;
}Queue;

Queue *queue_array_new(){
    Queue *queue;
    queue = malloc(sizeof(Queue));
    queue->j = 0;
    queue->size = 0;
    queue->capacity = 5;
    queue->data = malloc(sizeof(int)*5);
    return queue;
}
