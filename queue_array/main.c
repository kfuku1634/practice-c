#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue_array.c"

void run_test();
void run_new_test();
void run_add_test();
void run_remove_test();

int main(int argc, char* argv[]) {
    run_test(); 
    return EXIT_SUCCESS;
}

void run_test(){
    run_new_test();
    run_add_test();
    run_remove_test();
}

void run_new_test(){
    Queue *queue;
    queue = queue_array_new();

    assert( queue->start == 0 );
    assert( queue->size == 0 );
    assert( queue->capacity == 5 ); 

    queue_destroy(queue);
}

void run_add_test(){
    Queue *queue;
    queue = queue_array_new();

    queue_array_add(queue, 1);
    assert( *(queue->data) == 1);
    assert( queue->size == 1);

    queue_array_add(queue, 2);
    assert( *(queue->data) == 1);
    assert( *((queue->data)+1) == 2);
    assert( queue->size == 2);

    queue_destroy(queue);

    return;
}

void run_remove_test(){
    Queue *queue;
    queue = queue_array_new();

    queue_array_add(queue, 1);
    queue_array_add(queue, 2);
    queue_array_add(queue, 3);
    queue_array_add(queue, 4);

    assert( queue_array_remove(queue) == 1 );
    assert( queue_array_remove(queue) == 2 );
    assert( queue_array_remove(queue) == 3 );
    assert( queue_array_remove(queue) == 4 );

    queue_destroy(queue);
}
