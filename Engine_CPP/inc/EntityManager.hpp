#ifndef COW_ENTITYMANAGER
#define COW_ENTITYMANAGER
#include <map>
#include <vector>
#include "PositionComponent.hpp"
#include "ShapeComponent.hpp"
namespace cow {
class EntityManager {
   public:
    EntityManager();
    std::map<int, cow::PositionComponent> Positions;
    std::map<int, cow::ShapeComponent> Shapes;
};
};  // namespace cow
#endif