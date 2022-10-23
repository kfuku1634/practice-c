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

void linked_list_insert(my_linked_list *linked_list, int index, int insert_num){
    my_node *before_node, *new_node;
    if (index==0){
        linked_list_add(linked_list, insert_num);
        return;
    }
    new_node = malloc(sizeof(my_node));
    before_node = get_node(linked_list, index-1);
    new_node->data = insert_num;
    new_node->next_ptr = before_node->next_ptr;
    before_node->next_ptr = new_node;

    return;
}

void linked_list_push(my_linked_list *linked_list, int num ){
    my_node *new_node, *head_node;
    new_node = malloc(sizeof(my_node));
    if ( linked_list->n == 0 ){
        linked_list->head = new_node;
        linked_list->tail = new_node;
        new_node->next_ptr = NULL;
    }
    else{
        head_node = linked_list->head;
        linked_list->head = new_node;
        new_node->next_ptr = head_node;
    }
    new_node->data = num;
    linked_list->n++;
    return;
}

int linked_list_pop(my_linked_list *linked_list){
    return linked_list_remove(linked_list);
}