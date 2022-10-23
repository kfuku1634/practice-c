#include <stdlib.h>

my_node *get_node(my_linked_list *linked_list, int target_index){
    my_node *node, *tmp_node;
    int i;
    node = linked_list->head;
    for ( i = 0 ; i < target_index ; i++ ){
        node = node->next_ptr;
    }
    return node;
}

my_linked_list *linked_list_new(){
    my_linked_list *linked_list;
    linked_list = malloc(sizeof(my_linked_list));
    linked_list->n = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;
    return linked_list;
}

void linked_list_add(my_linked_list *linked_list, int add_num){
    my_node *new_node, *tail_node;
    new_node = malloc(sizeof(my_node));
    if ( linked_list->n == 0 ){
        linked_list->head = new_node;
    }
    else{
        tail_node = linked_list->tail;
        tail_node->next_ptr = new_node;
    }
    new_node->data = add_num;
    new_node->next_ptr = NULL;
    linked_list->tail = new_node;
    linked_list->n++;
    return;
}

int linked_list_remove(my_linked_list *linked_list){
    my_node *head_node;
    int ret;

    head_node = linked_list->head;
    ret = head_node->data;
    linked_list->n--;
    linked_list->head = head_node->next_ptr;

    return ret;
}