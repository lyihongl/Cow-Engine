#ifndef COW_MEMORYHASHTEST_H
#define COW_MEMORYHASHTEST_H
#include "../MemoryHash.h"
#include <stdio.h>
#include "../../log.c/src/log.h"

short MemHashUpsizeTest(){
    MemHashMap *m = (MemHashMap*)calloc(1, sizeof(MemHashMap));
    MemHashInit(m);
    log_debug("Got here");
    
    for(;m -> elements < 32;){
        int * a = (int*)malloc(sizeof(int));
        MemHashAdd(m, a, &a);
    }
    int x = 0;
    for(int i = 0; i<64; i++){
        if(m->table[i] != NULL){
            log_debug("i: %d val: %p size: %d", i, m->table[i]->head, m->table[i]->size);
            x++;
        }
    }
    log_debug("total values: %d", x);
    log_debug("elements: %d", m->elements);
    log_debug("Got here");
    return 0;
}
#endif