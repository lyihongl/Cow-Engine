#ifndef COW_POSITIONCOMPONENT
#define COW_POSITIONCOMPONENT
namespace cow {

class PositionComponent {
   private:
    int x, y, entityId;

   public:
    PositionComponent(int entityId);
    int GetX();
    int GetY();
    void SetX(int x);
    void SetY(int y);
    void GetEntityId();
};
};  // namespace cow
#endif
