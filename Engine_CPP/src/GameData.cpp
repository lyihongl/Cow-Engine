#include "../inc/GameData.hpp"
#include <iostream>

cow::GameData::GameData(int w, int h) : 
    p_window(std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(
        SDL_CreateWindow(
            "Test Window",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            w,
            h,
            SDL_WINDOW_OPENGL),
        SDL_DestroyWindow)),
    p_renderer(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(
        SDL_CreateRenderer(
            p_window.get(), -1, SDL_RENDERER_ACCELERATED),
        SDL_DestroyRenderer)){
        std::unique_ptr<RenderEngine> temp = std::make_unique<RenderEngine>(p_window.get(), p_renderer.get());
        p_renderEngine = std::move(temp);
        //std::unique_ptr<EntityManager> temp2 = 
        auto temp2 = std::make_unique<EntityManager>();
        P_entityManager = std::move(temp2);
    };

auto cow::GameData::P_getWindow() const -> SDL_Window* {
    return p_window.get();
}

auto cow::GameData::P_getRenderer() const -> SDL_Renderer* {
    return p_renderer.get();
}

auto cow::GameData::P_getRenderEngine() const -> RenderEngine* {
    std::cout << __FILE__ << __LINE__ << std::endl;
    std::cout << p_renderEngine.get() << std::endl;
    return p_renderEngine.get();
}

auto cow::GameData::P_getEntityManager() const -> EntityManager* {
    std::cout << __FILE__ << __LINE__ << std::endl;
    return P_entityManager.get();
}

bool cow::GameData::GetRunning() const {
    return running;
}

void cow::GameData::SetRunning(bool running) {
    this->running = running;
}
void cow::GameData::SetRunning(ERunning running) {
    switch (running) {
        case ERunning::YES:
            this->running = true;
            break;
        case ERunning::NO:
            this->running = false;
            break;
        default:
            this->running = false;
    }
}