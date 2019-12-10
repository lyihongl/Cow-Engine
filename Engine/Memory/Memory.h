#ifndef COW_MEMORY_H
#define COW_MEMORY_H
#include <stdlib.h>
#include <stdio.h>

typedef struct MemoryManager{
    long used_memory[2048];
} MemoryManager;

void* ManagedAlloc(MemoryManager *m, unsigned int bytes) {
    return (void*)malloc(bytes);
}
#endif