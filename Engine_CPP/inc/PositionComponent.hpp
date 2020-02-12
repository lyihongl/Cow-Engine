#ifndef COW_POSITIONCOMPONENT
#define COW_POSITIONCOMPONENT
namespace cow {

class PositionComponent {
   private:
    int x, y, parentId, id;

   public:
    PositionComponent();
    PositionComponent(int parentId);
    PositionComponent(int parentId, int x, int y);
    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);
    int GetParentId() const;
};
};  // namespace cow
#endif
