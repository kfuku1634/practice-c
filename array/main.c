#include <stdio.h>
#include <stdlib.h>
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
    printf("%p\n",arr);
    printf("%d\n",arr->size);
    printf("%p\n",arr->data);
}
