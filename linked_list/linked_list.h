typedef struct My_node my_node;
struct My_node{
    int data;
    my_node *next_ptr;
};

typedef struct My_linked_list {
    int n;
    my_node *head;
    my_node *tail;
}my_linked_list;