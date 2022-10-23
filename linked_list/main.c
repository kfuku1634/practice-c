#include <assert.h>
#include "linked_list.h"
#include "linked_list.c"

void run_all_tests();
void test_new();
void test_push();

int main(){
    run_all_tests();
}

void run_all_tests(){
    test_new();
    test_push();
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

void test_push(){
    my_linked_list *linked_list;
    linked_list = linked_list_new();
    linked_list_push(linked_list, 5);
    assert(linked_list->n == 1);
    assert(linked_list->head->data == 5);
    assert(linked_list->head->next_ptr == NULL);
    return;
}