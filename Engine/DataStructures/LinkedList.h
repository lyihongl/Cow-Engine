#ifndef COW_LINKEDLIST_H
#define COW_LINKEDLIST_H
#include <stdlib.h>
#include "../Debugging/MemoryProfile.h"

typedef struct Node {
    struct Node *next;
    void *data;
} Node;

typedef struct LinkedList {
    struct Node *head;
} LinkedList;

void LLFree(LinkedList *l){
    Node* head = l -> head -> next;
    Node* del = l -> head;
    while(del != NULL) {
        Cow_free(del);
        del = head;
        head = head->next;
    }
}

void LLInsert(LinkedList *l, Node *n) {
    n -> next = l -> head;
    l -> head = n;
}

#endif