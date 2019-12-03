#ifndef COW_LINKEDLIST_H
#define COW_LINKEDLIST_H

typedef struct Node {
    Node *next;
    void *data;
} Node;

typedef struct LinkedList {
    Node *p_head;
} LinkedList;

void LLInsert(LinkedList *l, Node *n) {
    n -> next = l -> p_head;
    l -> p_head = n;
}

#endif