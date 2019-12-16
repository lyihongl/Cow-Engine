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