#ifndef COW_GRAPHICSCOMPONENT
#define COW_GRAPHICSCOMPONENT
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
namespace cow {
class ShapeComponent {
   public:
    enum shape { rect,
                 circle };
    ShapeComponent(int entityId, shape s, int w, int h);
    void SetWidth(int w);
    void SetHeight(int h);
    int GetWidth() const;
    int GetHeight() const;
    int GetParentId() const;
    int GetId() const;
    shape GetShape() const;

   private:
    shape s;
    int w, h, parentId, id;
};
}  // namespace cow
#endif