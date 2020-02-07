#ifndef COW_GRAPHICSCOMPONENT
#define COW_GRAPHICSCOMPONENT
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>
namespace cow {
class ShapeComponent {
   private:
    enum shape { rect,
                 circle };
    shape s;
    int w, h, entityId;

   public:
    ShapeComponent(int entityId, shape s, int w, int h);
    void SetWidth(int w);
    void SetHeight(int h);
    int GetWidth();
    int GetHeight();
    void GetEntityId();
};
}  // namespace cow
#endif