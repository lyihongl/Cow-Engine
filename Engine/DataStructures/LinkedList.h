#ifndef COW_LINKEDLIST_H
#define COW_LINKEDLIST_H
#include <stdlib.h>
#include "../log.c/src/log.h"
//#include "../Debugging/MemoryProfile.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    void *data;
} Node;

typedef struct LinkedList {
    struct Node *head;
    struct Node *tail;
    int size;
} LinkedList;


Node* NodeInit(void* data);

void LLInit(LinkedList **l);
void LLFree(LinkedList *l);
void LLInsert(LinkedList *l, Node *n);
void LLPopHead(LinkedList* l);



#endif