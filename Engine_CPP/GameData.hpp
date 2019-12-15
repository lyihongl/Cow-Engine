#ifndef COW_GAMEDATA_HPP
#define COW_GAMEDATA_HPP
#include <SDL2/SDL.h>

class GameData{
    private:
    SDL_Window* p_window;
    SDL_Renderer* p_renderer;
    public:
    GameData(){
        p_window = SDL_CreateWindow(
            "An SDL2 window",                  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            1080,                               // width, in pixels
            720,                               // height, in pixels
            SDL_WINDOW_OPENGL     
        );
        p_renderer = SDL_CreateRenderer(p_window, -1, SDL_RENDERER_ACCELERATED);
    }
    SDL_Window* P_get_window(){
        return p_window;
    }
    SDL_Renderer* P_get_renderer(){
        return p_renderer;
    }
};
#endif