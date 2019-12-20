#ifndef COW_GAMEDATA_HPP
#define COW_GAMEDATA_HPP
#include <SDL2/SDL.h>
#include <memory>

/**
 * Holds basic data required for starting the application
 */
class GameData{
    private:

    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> p_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> p_renderer;
    bool running;

    public:

    GameData();
    const auto P_getWindow();
    const auto P_getRenderer();    
    bool GetRunning();
};
#endif