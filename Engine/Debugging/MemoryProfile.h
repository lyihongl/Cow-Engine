#ifndef COW_MEMORYPROFILE_H
#define COW_MEMORYPROFILE_H
#include <stdlib.h>
#include "../DataStructures/MemoryHash.h"
#define MEM_DEBUG 0
#if MEM_DEBUG
#define malloc(x) Cow_malloc(x)
#define calloc(x, y) Cow_calloc(x, y)
#endif

void* Cow_malloc(int size);
void* Cow_malloc(int size){
    if(MEM_DEBUG) {
        //allocate to hash
    }
    return (void*)malloc(size);
}

void Cow_free(void* addr) {
    if(MEM_DEBUG) {
        //remove from hash
    }
    free(addr);
}

#endif