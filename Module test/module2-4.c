#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node_t;

void printNodes(node_t* node) {
    node_t* itr = node; //create an iterator
    while (itr != NULL) {
        print("%d\n", itr->data);
        itr = itr->next;
    }
}

int main() {
    node_t node1;
    node_t node2;
    node_t node3;

    node1.data = 1;
    node2.data = 2;
    node3.data = 3;

    node1.next = &node2;
    node2.next = &node3;
    node3.next = NULL;


    



    return 0;
}