#include "../inc/GameData.hpp"

cow::GameData::GameData(int w, int h) : p_window(
                                            std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>(
                                                SDL_CreateWindow(
                                                    "An SDL2 window",         // window title
                                                    SDL_WINDOWPOS_UNDEFINED,  // initial x position
                                                    SDL_WINDOWPOS_UNDEFINED,  // initial y position
                                                    w,                        // width, in pixels
                                                    h,                        // height, in pixels
                                                    SDL_WINDOW_OPENGL),
                                                SDL_DestroyWindow)),
                                        p_renderer(std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>(
                                            SDL_CreateRenderer(
                                                p_window.get(), -1, SDL_RENDERER_ACCELERATED),
                                            SDL_DestroyRenderer)),
                                        running{false},
                                        p_renderEngine{std::make_unique<RenderEngine>(p_window.get(), p_renderer.get())} {};

auto cow::GameData::P_getWindow() const -> SDL_Window* {
    return p_window.get();
}

auto cow::GameData::P_getRenderer() const -> SDL_Renderer* {
    return p_renderer.get();
}

auto cow::GameData::P_getRenderEngine() const -> RenderEngine* {
    return p_renderEngine.get();
}

auto cow::GameData::P_getEntityManager() const -> EntityManager* {
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