#ifndef COW_POSITIONCOMPONENT
#define COW_POSITIONCOMPONENT
namespace cow {

class PositionComponent {
   private:
    int x, y, parentId, id;

   public:
    PositionComponent();
    PositionComponent(int parentId);
    int GetX();
    int GetY();
    void SetX(int x);
    void SetY(int y);
    void GetParentId();
};
};  // namespace cow
#endif
