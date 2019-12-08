#include "../LinkedList.h"
#include <stdio.h>
#include "../../log.c/src/log.h"

int LLTest(){
    LinkedList *l = NULL;
    log_debug("here");
    LLInit(&l);
    
    int data[10] = {0};
    for(int i = 0; i<10; i++){
        Node *n = NodeInit(&data[i]);
        LLInsert(l, n);
    }
    for(Node *a= l->head; a->next!=NULL; a = a->next){
        if((int*)(a->next->data) - (int*)(a->data) != -1) {
            return 1;
        }
    }
    for(Node *a = l->tail; a->prev != NULL; a = a->prev){
        if((int*)(a->data) - (int*)(a->prev->data) != -1) {
            return 2;
        }
    }
    
    return 0;
}