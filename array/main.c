#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.c"

void run_all_test();
void array_new_test();
void array_add_test();
void array_get_test();

int main(int argc, char* argv[]) {
    run_all_test();
    return EXIT_SUCCESS;
}

void run_all_test(){
    array_new_test();
    array_add_test();
    array_get_test();
}

void array_new_test(){
    Array *arr;
    arr = array_new();
    assert( arr->size == 0);
    assert( arr->capacity == 5);
    return;
}

void array_add_test(){
    Array *arr;
    array_add(arr, 0 , 3);
    assert( *(arr->data) == 3 );
    assert( (arr->size) == 1 );
    assert( (arr->capacity) == 5 );

    array_add(arr, 0 , 1);
    assert( *(arr->data) == 1 );
    assert( *((arr->data)+1) == 3 );
    assert( (arr->size) == 2 );
    assert( (arr->capacity) == 5 );

    array_add(arr, 0 , 4);
    assert( *(arr->data) == 4 );
    assert( *((arr->data)+1) == 1 );
    assert( *((arr->data)+2) == 3 );
    assert( (arr->size) == 3 );
    assert( (arr->capacity) == 5 );

    array_add(arr, 2 , 2);
    array_add(arr, 1 , 5);
    assert( *( arr->data   ) == 4 );
    assert( *((arr->data)+1) == 5 );
    assert( *((arr->data)+2) == 1 );
    assert( *((arr->data)+3) == 2 );
    assert( *((arr->data)+4) == 3 );
    assert( (arr->size) == 5 );
    assert( (arr->capacity) == 5 );

    array_add(arr, 0 , 10);
    assert( (arr->size) == 6 );
    assert( (arr->capacity) == 10 );

    return;
}

void array_get_test(){
    Array *arr;
    array_add(arr,0,1);
    array_add(arr,1,2);
    array_add(arr,2,3);
    array_add(arr,3,4);
    array_add(arr,4,5);
    array_add(arr,5,6);

    assert(array_get(arr, 0) == 1 );
    assert(array_get(arr, 1) == 2 );
    assert(array_get(arr, 2) == 3 );
    assert(array_get(arr, 3) == 4 );
    assert(array_get(arr, 4) == 5 );
    assert(array_get(arr, 5) == 6 );


}
