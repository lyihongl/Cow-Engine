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

    enum Running{YES = 1, NO = 0};
    GameData(int w=1080, int h=720);
    auto P_getWindow() const -> SDL_Window*;
    auto P_getRenderer() const -> SDL_Renderer*;    
    bool GetRunning() const;
    void SetRunning(bool running);
    void SetRunning(Running running);
};
#endif