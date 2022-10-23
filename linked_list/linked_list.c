#include <stdlib.h>

my_linked_list *linked_list_new(){
    my_linked_list *linked_list;
    linked_list = malloc(sizeof(my_linked_list));
    linked_list->n = 0;
    linked_list->head = NULL;
    linked_list->tail = NULL;
    return linked_list;
}