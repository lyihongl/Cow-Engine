#pragma once

#include <cstdint>
#include <memory>

namespace Cow {
static std::size_t incrementing_id{0};
struct Entity {
    Entity(uint32_t id) {
        ID = id;
    }
    uint32_t ID;
};

std::unique_ptr<Entity> NewEntity() {
    return std::unique_ptr<Entity>(new Entity{incrementing_id++});
}
uint32_t NewEntityID(){
    return incrementing_id++;
}
};  // namespace Cow