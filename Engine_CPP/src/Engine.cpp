#include "../inc/Engine.hpp"
#include <iostream>
#include <chrono>

#define chrono std::chrono
using millis = chrono::milliseconds;

void cow::StartGame() {
    SDL_Init(SDL_INIT_EVERYTHING);
    cow::GameData p_gd{};
    p_gd.SetRunning(cow::GameData::ERunning::YES);

    cow::Init(p_gd);

    cow::GameLoop(p_gd);
}

void cow::GameLoop(GameData& p_gd) {
    SDL_Event e;
    uint8_t running = 1;

    millis startTime = chrono::duration_cast<millis>(chrono::system_clock::now().time_since_epoch());
    millis currentTime = chrono::duration_cast<millis>(chrono::system_clock::now().time_since_epoch());

    for (; p_gd.GetRunning();) {
        currentTime = chrono::duration_cast<millis>(chrono::system_clock::now().time_since_epoch());
        if(currentTime.count()-startTime.count() > 17){
            startTime = chrono::duration_cast<millis>(chrono::system_clock::now().time_since_epoch());

            SDL_RenderClear(p_gd.P_getRenderer());
            SDL_PollEvent(&e);

            cow::Tick(p_gd);
            cow::Render(p_gd);
            //std::cout << __LINE__ << std::endl;
            p_gd.P_getRenderEngine()->RenderShape(p_gd.P_getEntityManager()->Positions, p_gd.P_getEntityManager()->Shapes);
            //std::cout << __LINE__ << std::endl;

            if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
                p_gd.SetRunning(cow::GameData::ERunning::NO);
            }
            SDL_RenderPresent(p_gd.P_getRenderer());
        }
    }
}