#ifndef COW_ENGINE_HPP
#define COW_ENGINE_HPP
#include <SDL2/SDL.h>
#include "GameData.hpp"

/*

Style guide

All objects will start with capital letter
The project will primarly use snake case with 1 expection.=

ALl private/protected member's will begin with lower case letter
All public member's will begin with upper case letter, except for pointers
All pointers will be prefixed with p_ or P_ depending on public or private

All parameters will start with lower case letter

*/

void Tick(GameData* p_gd);
void Render(GameData* p_gd);
void StartGame();
void GameLoop(GameData* p_gd);

void Tick(GameData* p_gd){

}
void Render(GameData* p_gd){

}

void StartGame(){
    GameData* p_gd = new GameData();
    GameLoop(p_gd);
}

void GameLoop(GameData* p_gd){
    SDL_Event e;
    uint8_t running = 1;

    for(;running;) {

        SDL_RenderClear(p_gd -> P_get_renderer());
        SDL_PollEvent(&e);
        Tick(p_gd);
        Render(p_gd);
        //printf("game loop\r\n");
        //RenderShape(&(d->rects), d -> window, d -> r, &(d -> ro));

        if(e.window.event == SDL_WINDOWEVENT_CLOSE){
            running = 0;
        }
        SDL_RenderPresent(p_gd -> P_get_renderer());
    }
}

#endif