#include "Engine.hpp"

void StartGame(){
    SDL_Init(SDL_INIT_EVERYTHING);
    GameData p_gd{};
    p_gd.SetRunning(GameData::Running::YES);
    GameLoop(p_gd);
}

void GameLoop(GameData& p_gd){
    SDL_Event e;
    uint8_t running = 1;

    for(;p_gd.GetRunning();) {

        SDL_RenderClear(p_gd.P_getRenderer());
        SDL_PollEvent(&e);

        Tick(p_gd);
        Render(p_gd);

        if(e.window.event == SDL_WINDOWEVENT_CLOSE){
            running = 0;
        }
        SDL_RenderPresent(p_gd.P_getRenderer());
    }
}