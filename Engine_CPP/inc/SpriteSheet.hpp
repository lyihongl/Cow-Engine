#ifndef COW_SPRITESHEET
#define COW_SPRITESHEET
#include <string>
#include <SDL2/SDL.h>
#include <memory>

class SpriteSheet{
   public:
    SpriteSheet(std::string path, int row, int column);
   private:
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> spriteImage;
    SDL_Rect clip;
};
#endif