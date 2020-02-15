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
    std::vector<cow::PositionComponent> Positions;
    std::vector<cow::ShapeComponent> Shapes;
    // insert worst case O(n), search time of list O(log(n))
    void AddShape(ShapeComponent &s);
    void AddPosition(PositionComponent &p);
};
};  // namespace cow
#endif