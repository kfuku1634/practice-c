#include <stdlib.h>
#include "array.h"

Array *array_new(){
    Array *arr;
    arr = malloc(sizeof(Array));
    arr->size = 0;
    arr->capacity = 5;
    arr->data = malloc(sizeof(int));
    return arr;
}

