#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node* next;
}node_t;


typedef struct slist {
    node_t* head;
    node_t* tail;
    int size;
}slist_t;


slist_t* makeSList() {
    slist_t* newList = (slist_t*)malloc(sizeof(slist_t));
    if (newList == NULL) return NULL;

    newList->head = NULL; //if not initialized, might get garbage value in C
    newList->tail = NULL;
    newList->size = 0;
}

int push_front(slist_t* slist, int value) {
    if (slist == NULL) return 0;

    node_t* newNode = makeNode(value);
    if (newNode == NULL) return 0;

    if (slist->head == NULL && slist->tail == NULL) {
        slist->tail = newNode;
    }
    newNode->next = slist->head;
    slist->head = newNode;

}




void printNodes(node_t* node) {
    node_t* itr = node; //create an iterator
    while (itr != NULL) {
        print("%d\n", itr->data);
        itr = itr->next;
    }
}


node_t* makeNode(int data) {
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    if (newNode == NULL) return NULL;

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void freeNode(node_t* node) {
    if (node == NULL) return;
    free(node);
}




int main() {
    node_t* node1 = makeNode(1);
    node_t* node2 = makeNode(2);
    node_t* node3 = makeNode(3);

    // node1.data = 1;
    // node2.data = 2;
    // node3.data = 3;

    node1->next = node2; //manually creating the list is cumbersome
    node2->next = node3;
    node3->next = NULL;

    printNodes(node1);

    freeNode(node1);
    freeNode(node2);
    freeNode(node3);

    return 0;
}