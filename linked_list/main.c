#include <assert.h>
#include <stdio.h>
#include "linked_list.h"
#include "linked_list.c"

void run_all_tests();
void test_new();
void test_queue();

int main(){
    run_all_tests();
}

void run_all_tests(){
    test_new();
    test_queue();
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

void test_queue(){
    my_linked_list *linked_list;
    linked_list = linked_list_new();

    my_node *node;

    linked_list_add(linked_list, 5);
    assert(linked_list->n == 1);
    node = get_node(linked_list ,0);
    assert(node->data == 5);
    assert(node->next_ptr == NULL);

    linked_list_add(linked_list, 10);
    assert(linked_list->n == 2);
    node = get_node(linked_list ,0);
    assert(node->data == 5);
    node = get_node(linked_list ,1);
    assert(node->data == 10  );
    assert(node->next_ptr == NULL  );

    assert( linked_list_remove(linked_list) == 5 );
    assert(linked_list->n == 1);
    node = get_node(linked_list ,0);
    assert(node->data == 10);
    assert(node->next_ptr == NULL);

    return;
}