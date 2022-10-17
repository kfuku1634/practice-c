#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "array.h"

Array *array_new(){
    Array *arr;
    arr = malloc(sizeof(Array));
    arr->size = 0;
    arr->capacity = 5;
    arr->data = malloc(sizeof(int));
    return arr;
}

void array_print( Array *arr){
    int i=0;
    for( i = 0; i < arr->size; i++ ){
        printf("%d ",*((arr->data)+i));
    }
    printf("\n");
}

void array_resize( Array *arr ){
    Array *arr_new;
    int re_size;
    re_size = arr->size ? (arr->size)*2 : 1;
    arr->capacity = re_size;
    arr->data = realloc( arr->data, arr->capacity );
    return;
}

void array_add(Array *arr, int i, int x){
    if ( (arr->capacity) == (arr->size) ){
        array_resize(arr);
    }
    memmove( (arr->data)+i+1, (arr->data)+i, ((arr->size)-i) * sizeof(int) );
    *((arr->data)+i) = x;
    arr->size += 1;
    return;
}

int array_get(Array *arr, int i){
    return *((arr->data)+i);
}

int array_set(Array *arr, int i, int x){
    int ret;
    ret = *((arr->data)+i);
    *((arr->data)+i) = x;
    return ret;
}
