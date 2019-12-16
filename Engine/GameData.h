#ifndef COW_GAMEDATA_H
#define COW_GAMEDATA_H
#include <SDL2/SDL.h>
#include "Graphics/Shape.h"
typedef struct GameData GameData;

struct GameData{
    // fill in definition here
    SDL_Window *window;
    SDL_Renderer *r;
    SofAShape *rects;
    RendererOptions *ro;
};
#endif