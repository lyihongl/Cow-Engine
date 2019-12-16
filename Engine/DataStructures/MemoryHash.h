#ifndef COW_MEMORYHASH_H
#define COW_MEMORYHASH_H
#include "LinkedList.h"
#include "../log.c/src/log.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t hashFunctionInt(void *addr);
typedef struct MemHashMap {
    int cap;
    int elements;
    LinkedList **table;
} MemHashMap;

/**
 * Initializes the HashMap used by the memory logger
 */
void MemHashInit(MemHashMap *mhp) {
    mhp -> cap = 32;
    mhp -> elements = 0;
    mhp -> table = (LinkedList**)calloc(1, mhp -> cap*sizeof(LinkedList*));
}

/**
 * Add an element to the MemHashMap, will automatically upsize when needed
 */
void MemHashAdd(MemHashMap *mhp, void *key, void *data) {

    // if there are less than 5 spaces left in the map
    if(mhp -> cap - mhp -> elements < 5){
        //upsize  
        LinkedList **temp = (LinkedList**)calloc(1, mhp -> cap*2*sizeof(LinkedList*));
        for(int i = 0; i<mhp -> cap; i++) {
            if(mhp -> table[i] != NULL){
                temp[i] = mhp -> table[i];
            }
        }
        free(mhp -> table);
        mhp -> table = temp;
        mhp -> cap = mhp->cap*2;
        log_debug("upsizing");
        log_debug("cap: %d", mhp->cap);
    }

    uint64_t hash = hashFunctionInt(key) % mhp -> cap;

    void** _data = calloc(2, sizeof(void*));
    _data[0] = key;
    _data[1] = data;
    Node *n = NodeInit(_data);

    //log_debug("Node val: %p", n);
    //log_debug("Data: %p", data);
    //log_debug("node data: %p", n->data);

    if(mhp -> table[hash] == NULL){
        LLInit(&(mhp -> table[hash]));
        mhp -> elements++;
    }

    //insert data into data table located at hash(key)
    LLInsert(mhp -> table[hash], n);
    //log_debug("Hash head data: %p", ((void**)(mhp -> table[hash] -> head -> data))[1]);
}

/**
 * Remove element from MemHashMap, will not downsize
 */
void MemHashRemove(MemHashMap *mhp, void *key){
    // not going downsize hash since thats just a pain
    uint64_t hash = hashFunctionInt(key) % mhp -> cap;
    if(mhp -> table[hash] -> size == 1) {
        LLPopHead(mhp -> table[hash]);
    }
}

void* MemHashGet(void* key){

}

/**
 * Uses a memory address as key for hash
 */
uint64_t hashFunctionInt(void *addr) {
    /* 
     * Austin Appleby's MurmurHash2, hardcoded to process a single
     * 64-bit input
     */
    //log_debug("here");
    uint64_t const a = 0xc6a4a7935bd1e995;
    //log_debug("here");
    uint64_t const b = 47;
    //log_debug("here");

    register uint64_t h = 8 * a;
    //log_debug("here");
    register uint64_t k = (uint64_t)(addr);
    //log_debug("here");
 
    k *= a;
    k ^= k >> b;
    k *= a;

    h ^= k;
    h *= a * a;

    h ^= h >> b;
    h *= a;
    h ^= h >> b;

    return h;
}

uint32_t hashFunctionStr(const char *key, uint32_t len, uint32_t seed) {
    uint32_t c1 = 0xcc9e2d51;
    uint32_t c2 = 0x1b873593;
    uint32_t r1 = 15;
    uint32_t r2 = 13;
    uint32_t m = 5;
    uint32_t n = 0xe6546b64;
    uint32_t h = 0;
    uint32_t k = 0;
    uint8_t *d = (uint8_t *)key; // 32 bit extract from `key'
    const uint32_t *chunks = NULL;
    const uint8_t *tail = NULL; // tail - last 8 bytes
    int i = 0;
    int l = len / 4; // chunk length

    h = seed;

    chunks = (const uint32_t *)(d + l * 4); // body
    tail = (const uint8_t *)(d + l * 4);    // last 8 byte chunk of `key'

    // for each 4 byte chunk of `key'
    for (i = -l; i != 0; ++i) {
        // next 4 byte chunk of `key'
        k = chunks[i];

        // encode next 4 byte chunk of `key'
        k *= c1;
        k = (k << r1) | (k >> (32 - r1));
        k *= c2;

        // append to hash
        h ^= k;
        h = (h << r2) | (h >> (32 - r2));
        h = h * m + n;
    }

    k = 0;

    // remainder
    switch (len & 3) { // `len % 4'
    case 3:
        k ^= (tail[2] << 16);
    case 2:
        k ^= (tail[1] << 8);
    case 1:
        k ^= tail[0];
        k *= c1;
        k = (k << r1) | (k >> (32 - r1));
        k *= c2;
        h ^= k;
    }

    h ^= len;

    h ^= (h >> 16);
    h *= 0x85ebca6b;
    h ^= (h >> 13);
    h *= 0xc2b2ae35;
    h ^= (h >> 16);

    return h;
}
#endif