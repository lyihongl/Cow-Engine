#ifndef COW_MEMORYHASH_H
#define COW_MEMORYHASH_H
#include "LinkedList.h"
#include "../log.c/src/log.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct MemHashMap {
    int cap;
    int elements;
    LinkedList **table;
} MemHashMap;

/**
 * Initializes the HashMap used by the memory logger
 */
void MemHashInit(MemHashMap *mhp);

/**
 * Add an element to the MemHashMap, will automatically upsize when needed
 */
void MemHashAdd(MemHashMap *mhp, void *key, void *data);

/**
 * Remove element from MemHashMap, will not downsize
 */
void MemHashRemove(MemHashMap *mhp, void *key);

void* MemHashGet(void* key);

/**
 * Uses a memory address as key for hash
 */
uint64_t hashFunctionInt(void *addr);


/**
 * TODO: THIS FUNCTION DOESN'T BELONG HERE
 */

#endif