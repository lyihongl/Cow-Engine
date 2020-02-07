#ifndef COW_RENDERENGINE
#define COW_RENDERENGINE
#include <SDL2/SDL.h>
#include <vector>
#include "ShapeComponent.hpp"
namespace cow {
class RenderEngine {
   public:
    RenderEngine(SDL_Window* w, SDL_Renderer* r);
    void RenderShape(std::vector<cow::ShapeComponent> s);
    void RenderGraphics();
};
};  // namespace cow
#endif