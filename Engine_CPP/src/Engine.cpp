#include "../inc/Engine.hpp"
#include <iostream>

void cow::StartGame() {
    SDL_Init(SDL_INIT_EVERYTHING);
    cow::GameData p_gd{};
    p_gd.SetRunning(cow::GameData::ERunning::YES);

    cow::Init(p_gd);
    std::cout<<SDL_GL_GetCurrentContext()<<std::endl;

    cow::GameLoop(p_gd);
}

void cow::GameLoop(GameData& p_gd) {
    SDL_Event e;
    uint8_t running = 1;

    for (; p_gd.GetRunning();) {
        SDL_RenderClear(p_gd.P_getRenderer());
        SDL_PollEvent(&e);

        cow::Tick(p_gd);
        cow::Render(p_gd);
        //std::cout << __LINE__ << std::endl;
        //std::cout << __LINE__ << std::endl;

        if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
            p_gd.SetRunning(cow::GameData::ERunning::NO);
        }
        SDL_RenderPresent(p_gd.P_getRenderer());
    }
}