#ifndef COW_GAMEOBJECT
#define COW_GAMEOBJECT
#include "ShapeComponent.hpp"
namespace cow {

    bool CheckComponents(int components, ECompType c);

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
    void EnableComponent(ECompType c);
    void AddComponent();
};
};  // namespace cow
#endif