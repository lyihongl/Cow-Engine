#include "GameData.hpp"

GameData::GameData(int w, int h): 
    p_window(std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(
        SDL_CreateWindow(
            "An SDL2 window",                  // window title
            SDL_WINDOWPOS_UNDEFINED,           // initial x position
            SDL_WINDOWPOS_UNDEFINED,           // initial y position
            w,                               // width, in pixels
            h,                               // height, in pixels
            SDL_WINDOW_OPENGL     
            ),
        SDL_DestroyWindow
        )),
    p_renderer(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(
        SDL_CreateRenderer(
            p_window.get(), -1, SDL_RENDERER_ACCELERATED
            ),
    SDL_DestroyRenderer)),
    running{false} {};

auto GameData::P_getWindow() const -> SDL_Window*{
    return p_window.get();
}

auto GameData::P_getRenderer() const -> SDL_Renderer*{
    return p_renderer.get();
}

bool GameData::GetRunning() const{
    return running;
}

void GameData::SetRunning(bool running){
    this->running = running;
}