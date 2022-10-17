#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue_array.c"

void run_test();
void run_new_test();

int main(int argc, char* argv[]) {
    run_test(); 
    return EXIT_SUCCESS;
}

void run_test(){
    run_new_test();
}

void run_new_test(){
    Queue *queue;
    queue = queue_new();

    assert( queue->j == 0 );
    assert( queue->size == 0 );
    assert( queue->capacity == 5 ); 

    free(queue);

}
