#ifndef COW_GRAPHICSCOMPONENT
#define COW_GRAPHICSCOMPONENT
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
#include "Component.hpp"
namespace cow {
enum shape { rect,
             circle };
class ShapeComponent : public Component{
   public:
    ShapeComponent(int id);
    ShapeComponent(int id, shape s, int w, int h);
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