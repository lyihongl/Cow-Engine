#ifndef COW_GAMEDATA_HPP
#define COW_GAMEDATA_HPP
#include <SDL2/SDL.h>
#include <memory>
#include "../inc/EntityManager.hpp"
#include "../inc/RenderEngine.hpp"
#include "../inc/GameObject.hpp"

namespace cow {
/**
 * Holds basic data required for starting the application
 */
class GameData {
   private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> p_window;
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> p_renderer;
    std::unique_ptr<RenderEngine> p_renderEngine;
    std::unique_ptr<EntityManager> P_entityManager;
    bool running;

   public:
    enum ERunning { YES = 1,
                    NO = 0 };
    GameData(int w = 1080, int h = 720);
    auto P_getWindow() -> SDL_Window*;
    auto P_getRenderer() -> SDL_Renderer*;
    auto P_getRenderEngine() -> RenderEngine*;
    auto P_getEntityManager() -> EntityManager*;
    bool GetRunning() const;
    void SetRunning(bool running);
    void SetRunning(ERunning running);
};
}  // namespace cow
#endif