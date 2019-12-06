#ifndef COW_LINKEDLIST_H
#define COW_LINKEDLIST_H
#include <stdlib.h>
//#include "../Debugging/MemoryProfile.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    void *data;
} Node;

typedef struct LinkedList {
    struct Node *head;
} LinkedList;

void LLFree(LinkedList *l){
    Node* head = l -> head -> next;
    Node* del = l -> head;
    while(del != NULL) {
        free(del);
        del = head;
        head = head->next;
    }
}

void LLInsert(LinkedList *l, Node *n) {
    if(l-> head == NULL){
        l -> head = n;
    } else {
        n -> next = l -> head;
        l -> head -> prev = n;
        l -> head = n;
    }
}

#endif