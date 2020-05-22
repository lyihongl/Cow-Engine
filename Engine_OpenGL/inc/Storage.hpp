#pragma once

#include <atomic>
#include <unordered_map>
#include <vector>
#include <memory>
#include <cstdarg>

namespace Cow {

constexpr size_t BLOCK_MEMORY_8K = 8192;

//forward declerations

struct World;  //context for which the ECS is in

//struct DataChunk;  //stores 8k of data;

struct Component;

struct ComponentContainer;

template <class ValueType>
class TypeMap;

template <class ValueType>
class TypeMap {
    // Internally, we'll use a hash table to store mapping from type
    // IDs to the values.
    typedef std::unordered_map<int, ValueType> InternalMap;

   public:
    typedef typename InternalMap::iterator iterator;
    typedef typename InternalMap::const_iterator const_iterator;
    typedef typename InternalMap::value_type value_type;

    const_iterator begin() const { return m_map.begin(); }
    const_iterator end() const { return m_map.end(); }
    iterator begin() { return m_map.begin(); }
    iterator end() { return m_map.end(); }

    // Finds the value associated with the type "Key" in the type map.
    template <class Key>
    iterator find() { return m_map.find(getTypeId<Key>())   ; }

    // Same as above, const version
    template <class Key>
    const_iterator find() const { return m_map.find(getTypeId<Key>()); }

    // Associates a value with the type "Key"
    template <class Key>
    void put(ValueType &&value) {
        m_map[getTypeId<Key>()] = std::forward<ValueType>(value);
    }
    template <class Key>
    void put(ValueType &value) {
        m_map[getTypeId<Key>()] = std::forward<ValueType>(value);
    }

   private:
    template <class Key>
    inline static int getTypeId() {
        static const int id = LastTypeId++;
        return id;
    }

    static std::atomic_int LastTypeId;
    InternalMap m_map;
};


//struct ComponentList;  // Stores component data

//struct Archetype;  // provides info about which components it stores, and access to the componentlist

//struct Entity;

//class TypeRegistry;

struct Component{
    uint32_t UniqueID;
    uint32_t CompID;
    uint32_t Version;
};


template <class ValueType>
std::atomic_int Cow::TypeMap<ValueType>::LastTypeId{0};


struct ComponentManager{
    std::vector<std::unique_ptr<ComponentContainer>> Components;

    TypeMap<uint32_t> TMap{};

    template <typename T>
    uint32_t Register();
    unsigned int uniqueKey{1};
};


struct ComponentContainer{
    std::vector<Component> data;
};


template <typename T>
uint32_t ComponentManager::Register(){
    if(TMap.find<T>() == TMap.end()){
        TMap.put<T>(uniqueKey);
        Components.push_back(std::make_unique<ComponentContainer>());
        uniqueKey++;
    }
}

//type flags
//const unsigned int INSTANCEOF = 1 << 63;
//const unsigned int CHILDOF = 1 << 62;
//
//using Type = std::vector<unsigned int>;
//using EntityID = uint32_t;
//using ComponentID = EntityID;
//using byte = unsigned char;
//
//struct Entity {
//    uint32_t ID;
//    uint32_t Version;
//};
//
//struct DataChunkHeader{
//    uint32_t ChunkID;
//    std::size_t NumComponents;
//};
//
//struct DataChunk {
//    //Header
//    DataChunkHeader Header;
//    std::unique_ptr<DataChunk> Next;
//    DataChunk* Prev;
//    /*
//    | Entity IDs | Components | Components | ... |
//    */
//    byte Data[BLOCK_MEMORY_8K - sizeof(DataChunkHeader) - sizeof(std::unique_ptr<DataChunk>) - sizeof(DataChunk*)];
//};
//
////number of components
////size of components
////potential cache miss
//Archetype* ArchetypeFactory(std::size_t numComp, ...){
//    va_list sizes;
//    va_start(sizes, numComp);
//    std::vector<uint32_t> byteSizes;
//    uint32_t totalSize{0};
//
//
//    //allocate new archtype
//    Archetype *t = new Archetype();
//
//    //vectorize types
//    for(std::size_t i{0}; i<numComp; i++){
//
//        //std::cout<<va_arg(sizes, uint32_t);
//        //container->push_back(va_arg(sizes, uint32_t));
//        uint32_t temp = va_arg(sizes,uint32_t);
//        byteSizes.push_back(temp);
//        totalSize += temp;
//
//    }
//    std::size_t allocAmount = BLOCK_MEMORY_8K - sizeof(DataChunkHeader) - sizeof(std::unique_ptr<DataChunk>) - sizeof(DataChunk*);
//};
//
////archetype container
//struct Archetype {
//    //data
//
//    //components list
//    std::vector<uint32_t> ComponentList;
//
//    DataChunk* Data;
//};
//
//struct World {
//
//    //Various archetype containers
//    std::vector<Archetype> ComponentStorage;
//
//    template <typename T>
//    void AddComponent(uint32_t ID /* component args here*/){
//        //check for component and its current archetype status
//    }
//};

//type registry


}  // namespace Cow