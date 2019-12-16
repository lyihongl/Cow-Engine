#include "LinkedList.h"

Node* NodeInit(void* data){
    Node *n = (Node*)calloc(1, sizeof(Node));
    n -> data = data;
    return n;
}

void LLInit(LinkedList **l){
    //log_debug("Initializing linked list");
    if(*l == NULL){
        *l = (LinkedList*)calloc(1, sizeof(LinkedList));
    } else {
        return;
    }
    (*l) -> head = NULL;
    (*l) -> tail = NULL;
    (*l) -> size = 0;
}

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
        log_debug("head: %p", l->head);
        l -> tail = n;
        l -> tail -> next = NULL;
        l -> head -> prev = NULL;
    } else {
        n -> next = l -> head;
        l -> head -> prev = n;
        l -> head = n;
    }
    l -> size++;
}

void LLPopHead(LinkedList* l){
    Node* temp = l->head;
    l -> head = l -> head -> next;
    free(temp);
}