#ifndef COW_ENTITYMANAGER
#define COW_ENTITYMANAGER
#include <vector>
#include "PositionComponent.hpp"
#include "ShapeComponent.hpp"
namespace cow {
class EntityManager {
   public:
    std::vector<cow::PositionComponent> Positions;
    std::vector<cow::ShapeComponent> Shapes;
};
};  // namespace cow
#endif