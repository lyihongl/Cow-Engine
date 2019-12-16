#include "MemoryHash.h"

void MemHashInit(MemHashMap *mhp) {
    mhp -> cap = 32;
    mhp -> elements = 0;
    mhp -> table = (LinkedList**)calloc(1, mhp -> cap*sizeof(LinkedList*));
}

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

void MemHashRemove(MemHashMap *mhp, void *key){
    // not going downsize hash since thats just a pain
    uint64_t hash = hashFunctionInt(key) % mhp -> cap;
    if(mhp -> table[hash] -> size == 1) {
        LLPopHead(mhp -> table[hash]);
    }
}

uint64_t hashFunctionInt(void *addr) {
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

    return h;
}