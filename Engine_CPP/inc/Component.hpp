#ifndef COW_COMPONENT
#define COW_COMPONENT
#include <memory>
namespace cow{
    enum ECompType{Position, Shape};
class Component{
   protected:
    int parentId, id;
    cow::ECompType type;
   public:
    Component(int id, int parentId, cow::ECompType type);
    void SetParentId(int id);
    int GetParentId() const;
    int GetId() const;

};
};
#endif