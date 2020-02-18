#ifndef COW_POSITIONCOMPONENT
#define COW_POSITIONCOMPONENT
#include "Component.hpp"
namespace cow {

class PositionComponent : public Component{
   private:
    int x, y;

   public:
    PositionComponent(int id);
    PositionComponent(int id, int x, int y);
    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);
    void RelativeX(int x);
    void RelativeY(int y);
};
};  // namespace cow
#endif
