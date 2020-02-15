#ifndef COW_GAMEOBJECT
#define COW_GAMEOBJECT
#include "ShapeComponent.hpp"
namespace cow {

    enum Components{Position, Shape};
    bool CheckComponents(int components, Components c){
        return components & (1<<c) != 0;
    }

class GameObject {
   private:
    //graphics componenet
    //physics component
    int id;
    int components;


   public:
    GameObject();
    GameObject(int id);
    GameObject(GameObject &g);
    int GetId() const;
    void EnableComponent(Components c);
};
};  // namespace cow
#endif