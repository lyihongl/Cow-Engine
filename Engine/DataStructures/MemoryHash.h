#ifndef COW_MEMORYHASH_H
#define COW_MEMORY_HASH_H
#include "LinkedList.h"

typedef struct MemHashTable{
    int size;
    LinkedList *table[];
};

void InitMemHash(MemHashTable *mht) {

}
#endif