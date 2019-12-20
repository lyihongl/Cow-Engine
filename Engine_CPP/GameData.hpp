#ifndef COW_GAMEDATA_HPP
#define COW_GAMEDATA_HPP
#include <SDL2/SDL.h>
#include <memory>
#include "Logistics.hpp"

/**
 * Holds basic data required for rendering
 */
class GameData{
    private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> p_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> p_renderer;
    public:
    GameData(): 
        p_window(std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(SDL_CreateWindow(
            "An SDL2 window",                  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            1080,                               // width, in pixels
            720,                               // height, in pixels
            SDL_WINDOW_OPENGL     
        ), SDL_DestroyWindow
        )),
        p_renderer(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(SDL_CreateRenderer(p_window.get(), -1, SDL_RENDERER_ACCELERATED),
        SDL_DestroyRenderer)) {};

    const auto P_get_window(){
        return p_window.get();
    }
    const auto P_get_renderer(){
        return p_renderer.get();
    }
};
#endif