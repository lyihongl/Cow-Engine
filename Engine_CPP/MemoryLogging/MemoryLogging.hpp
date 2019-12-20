#ifndef COW_MEMORYLOGGING_HPP
#define COW_MEMORYLOGGING_HPP
#define MEM_DEBUG 0


#if MEM_DEBUG
#include <iostream>
#include <map>
static std::map<const void*, bool> MemMap;
#include <iostream>
void* operator new(std::size_t size);
void* operator new(std::size_t size){
    void* ret = malloc(size);
    std::cout << __LINE__ << std::endl;
    MemMap.insert(std::make_pair(ret, true));
    std::cout << __LINE__ << std::endl;
    return ret;
}
#endif

#endif