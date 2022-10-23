#include <assert.h>
#include "linked_list.h"
#include "linked_list.c"

void run_all_tests();
void test_new();

int main(){
    run_all_tests();
}

void run_all_tests(){
    test_new();
    return;
}

void test_new(){
    my_linked_list *linked_list;
    linked_list = linked_list_new();
    assert(linked_list->n == 0);
    assert(linked_list->head == NULL);
    assert(linked_list->tail == NULL);
    return;
}