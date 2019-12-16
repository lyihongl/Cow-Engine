#ifndef COW_HASHMAP_H
#define COW_HASHMAP_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t hashFunctionStr(const char* key, uint32_t len, uint32_t seed);

#endif