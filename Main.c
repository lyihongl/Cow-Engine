#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include "Engine/Engine.h"
#include "Engine/Graphics/Shape.h"
#include "Engine/GameData.h"

void GameDataInit(GameData * d) {
    SDL_Init(SDL_INIT_EVERYTHING);

    d -> window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        1080,                               // width, in pixels
        720,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    d -> r = SDL_CreateRenderer(d -> window, -1, SDL_RENDERER_ACCELERATED);
    double temp[8] = {20, 20, 2, 2, 30, 30, 6, 4};
    double *shape_test = (double*)malloc(sizeof(double)*8);
    for(int i = 0; i<8; i++) {
        shape_test[i] = temp[i];
    }
    d -> rects = (SofaShape*)malloc(sizeof(SofaShape));
    d -> ro = (RendererOptions*)malloc(sizeof(RendererOptions));
    d -> rects -> shape = shape_test;
    d -> rects -> size = 8;
    d -> rects -> f = Rect;
    d -> ro -> a = 100;
    d -> ro -> r = 255;
    d -> ro -> b = 0;
    d -> ro -> g = 0;
}

void Tick(GameData *d){

}

void Render(GameData *d){
    RenderShape(d -> rects, d->window, d->r, d->ro);
}

int main(int argc, char** argv){
    GameData d;

    StartGame(&d);

    // Clean up
    SDL_DestroyWindow(d.window);
    SDL_Quit();

    return 0;
}