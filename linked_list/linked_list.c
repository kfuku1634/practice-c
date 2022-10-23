#include <stdlib.h>

my_linked_list *linked_list_new(){
    my_linked_list *linked_list;
    linked_list = malloc(sizeof(my_linked_list));
    linked_list->n = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;
    return linked_list;
}

void linked_list_push(my_linked_list *linked_list, int add_num){
    my_node *node;
    node = malloc(sizeof(my_node));
    linked_list->n = 1;
    linked_list->head = node;
    linked_list->tail = node;

    linked_list->head->data = 5;
    linked_list->head->next_ptr = NULL;
    return;
}