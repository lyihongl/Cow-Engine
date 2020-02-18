#ifndef COW_COMPONENT
#define COW_COMPONENT
#include <memory>
namespace cow{
class Component{
   protected:
    int parentId, id;
   public:
    Component(int id, int parentId);
    void SetParentId(int id);
    int GetParentId() const;
    int GetId() const;

};
};
#endif