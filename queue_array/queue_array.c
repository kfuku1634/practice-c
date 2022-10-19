#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

Queue *queue_array_new(){
    Queue *queue;
    queue = malloc(sizeof(Queue));
    queue->start = 0;
    queue->size = 0;
    queue->capacity = 5;
    queue->data = malloc(sizeof(int)*5);
    return queue;
}

void queue_print(Queue *queue){
    int i;

    for (i = 0; i < queue->capacity; i++){
        printf("%d ",*( (queue->data)+i ));
    }
    printf("\n");
    return;
}

void queue_array_resize( Queue *queue ){
    int re_size;
    int *new_data;
    int i;
    int queue_pos;

    re_size = (queue->size > 0) ? (queue->size)*2 : 1;
    new_data = malloc(re_size);

    for( i = 0; i < queue->size; i++ ){
        queue_pos = (queue->start + i ) % queue->capacity;
        *((new_data)+i) = *( (queue->data)+queue_pos );
    }
    queue->data = new_data;
    queue->capacity = re_size;
    queue->start = 0;
    return ;
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

int queue_array_remove(Queue *queue ){
    int res;
    if ( queue->size == 0 ){ return EXIT_FAILURE; }
    res = *((queue->data)+queue->start);
    queue->start += 1;
    queue->size -= 1;

    if ( (queue->size) * 3 <= (queue->capacity) ){
        queue_array_resize(queue);
    }

    return res;
}
