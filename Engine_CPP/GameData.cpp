#include "GameData.hpp"

GameData::GameData(): 
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
    SDL_DestroyRenderer)),
    running{false} {};

const auto GameData::P_getWindow(){
    return p_window.get();
}

const auto GameData::P_getRenderer(){
    return p_renderer.get();
}

bool GameData::GetRunning(){
    return running;
}