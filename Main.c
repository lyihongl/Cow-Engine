#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include "Engine/Engine.h"
#include "Engine/Graphics/Shape.h"
#include "Engine/GameData.h"
#include "Engine/Debugging/MemoryProfile.h"
#include "Engine/DataStructures/LinkedList.h"

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
    double temp[8] = {20, 20, 2, 2, 30, 30, 20, 20};
    double *shape_test = (double*)malloc(sizeof(double)*8);
    for(int i = 0; i<8; i++) {
        shape_test[i] = temp[i];
    }
    d -> rects = (SofaShape*)malloc(sizeof(SofaShape));
    d -> ro = (RendererOptions*)malloc(sizeof(RendererOptions));
    d -> rects -> shape = shape_test;
    d -> rects -> size = 8;
    d -> rects -> f = Rect;
    d -> ro -> rgba = (double*)malloc(4*3);
    d -> ro -> rgba[0] = 0;
    d -> ro -> rgba[1] = 0;
    d -> ro -> rgba[2] = 0;
    d -> ro -> rgba[3] = 0;
    d -> ro -> rgba[4] = 255;
    d -> ro -> rgba[5] = 0;
    d -> ro -> rgba[6] = 0;
    d -> ro -> rgba[7] = 255;
    d -> ro -> rgba[8] = 0;
    d -> ro -> rgba[9] = 255;
    d -> ro -> rgba[10] = 0;
    d -> ro -> rgba[11] = 255;
}

void GameDataFree(GameData *d) {
    free(d -> rects -> shape);
    free(d -> ro -> rgba);
    free(d -> rects);
    free(d -> ro);
    free(d);
}

void Tick(GameData *d){

}

void Render(GameData *d){
    RenderShape(d -> rects, d->window, d->r, d->ro);
}

int main(int argc, char** argv){
    int *a = (int*)malloc(sizeof(int));
    int *b = (int*)malloc(sizeof(int));
    int test = (int)hashFunctionInt(a, 32);
    int test2 = (int)hashFunctionInt(b, 32);
    printf("test: %d %d", test, test2);
    //GameData d;

    //StartGame(&d);
    //printf("%d\r\n", __LINE__);

    // Clean up
    //SDL_DestroyWindow(d.window);
    //SDL_Quit();

    return 0;
}