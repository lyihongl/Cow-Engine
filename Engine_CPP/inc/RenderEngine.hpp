#ifndef COW_RENDERENGINE
#define COW_RENDERENGINE
#include <SDL2/SDL.h>
#include <map>
#include "PositionComponent.hpp"
#include "ShapeComponent.hpp"
namespace cow {
class RenderEngine {
   private:
    SDL_Window* w;
    SDL_Renderer* r;

   public:
    RenderEngine(SDL_Window* w, SDL_Renderer* r);
    void RenderShape(std::map<int, PositionComponent> p, std::map<int, cow::ShapeComponent> s);
    void RenderGraphics();
};
};  // namespace cow
#endif