#include <stdlib.h>

typedef struct MyQueue {
    int start;
    int size;
    int capacity;
    int *data;
}Queue;

void queue_destroy( Queue *queue ){
    free(queue->data);
    free(queue);
    return;
}

void queue_array_resize( Queue *queue ){
    int re_size;
    re_size = (queue->size > 0) ? (queue->size)*2 : 1;
    queue->capacity = re_size;
    queue->data = realloc(queue->data, queue->capacity);
    return;
}

Queue *queue_array_new(){
    Queue *queue;
    queue = malloc(sizeof(Queue));
    queue->start = 0;
    queue->size = 0;
    queue->capacity = 5;
    queue->data = malloc(sizeof(int)*5);
    return queue;
}

void queue_array_add( Queue *queue, int x ){
    int add_pos;
    if ( (queue->size) == (queue->capacity) ){
        queue_array_resize(queue);
    }

    add_pos = ((queue->start)+(queue->size)) % (queue->capacity);
    *( (queue->data) + add_pos ) = x;
    queue->size +=1;
}
