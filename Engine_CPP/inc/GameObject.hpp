#ifndef COW_GAMEOBJECT
#define COW_GAMEOBJECT
#include "ShapeComponent.hpp"
namespace cow {

class GameObject {
   private:
    //graphics componenet
    //physics component

   public:
    GameObject();
    ShapeComponent c;
};
};  // namespace cow
#endif