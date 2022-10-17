#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.c"

void run_all_test();
void array_new_test();

int main(int argc, char* argv[]) {
    run_all_test();
    return EXIT_SUCCESS;
}

void run_all_test(){
    array_new_test();
}

void array_new_test(){
    Array *arr;
    arr = array_new();
    assert( arr->size == 0);
    assert( arr->capacity == 5);
}
