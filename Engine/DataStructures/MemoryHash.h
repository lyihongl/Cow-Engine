#ifndef COW_MEMORYHASH_H
#define COW_MEMORY_HASH_H
#include "LinkedList.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t hashFunctionInt(void *addr, int cap);
typedef struct MemHashMap {
    int cap;
    int elements;
    LinkedList **table;
} MemHashMap;

void InitMemHash(MemHashMap *mhp) {
    mhp -> cap = 32;
    mhp -> elements = 0;
    mhp -> table = (LinkedList**)malloc(mhp -> cap*sizeof(LinkedList*));
}

void MemHashAdd(MemHashMap *mhp, void *key, void *data) {
    // upsize
    printf("hello\r\n");
    //fflush(stdout);
    //if(mhp -> cap - mhp -> elements < 5){
        //mhp -> cap = mhp->cap * 2;
        //LinkedList **temp = (LinkedList**)malloc(mhp -> cap*sizeof(LinkedList*));
        //for(int i = 0; i < mhp -> elements; i++) {
            //temp[i] = mhp -> table[i];
        //}
        //free(mhp -> table);
        //mhp -> table = temp;
    //}

    //printf("hello\r\n");
    //fflush(stdout);

    //if(mhp -> cap - mhp -> elements > (mhp -> cap)/2 + 4){
        ////mhp -> cap = mhp -> cap / 2;
        ////LinkedList **temp = (LinekdList**)
    //}
    //int hash = hashFunctionInt(key, mhp -> cap);
    //Node *n = (Node*)malloc(sizeof(Node));
    //n -> data = data;
    //LLInsert(mhp -> table[hash], n);
}

uint64_t hashFunctionInt(void *addr, int cap) {
    /* 
     * Austin Appleby's MurmurHash2, hardcoded to process a single
     * 64-bit input
     */
    uint64_t const a = 0xc6a4a7935bd1e995;
    uint64_t const b = 47;

    register uint64_t h = 8 * a;
    register uint64_t k = (uint64_t)(addr);
 
    k *= a;
    k ^= k >> b;
    k *= a;

    h ^= k;
    h *= a * a;

    h ^= h >> b;
    h *= a;
    h ^= h >> b;

    return h % cap;
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