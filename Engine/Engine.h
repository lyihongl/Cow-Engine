#ifndef COW_ENGINE_H
#define COW_ENGINE_H
#include <SDL2/SDL.h>
#include "GameData.h"

//Functions undefined and left for the user to define

void GameDataInit(GameData *d);
void GameDataFree(GameData *d);

void Tick(GameData *d);
void Render(GameData *d);

void StartGame(GameData *d) {
    GameDataInit(d);
    if (d -> window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
    }
    GameLoop(d);

}
void GameLoop(GameData *d) {

    //GameData d;
    //StartGame(&d);
    SDL_Event e;
    uint8_t running = 1;

    for(;running;) {

        SDL_RenderClear(d -> r);
        SDL_PollEvent(&e);
        Tick(d);
        Render(d);
        //printf("game loop\r\n");
        //RenderShape(&(d->rects), d -> window, d -> r, &(d -> ro));

        if(e.window.event == SDL_WINDOWEVENT_CLOSE){
            running = 0;
        }
        SDL_RenderPresent(d -> r);
    }
}
void Tick();

#endif