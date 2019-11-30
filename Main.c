#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include "Engine/Engine.h"
#include "Engine/Graphics/Shape.h"

int main(int argc, char** argv){
    //int x = 4;
    //printf("%p\r\n", &x);
    SDL_Window *window;
    SDL_Init(SDL_INIT_EVERYTHING);
    //SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        1080,                               // width, in pixels
        720,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }


    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Event e;
    Uint32 windowID = SDL_GetWindowID(window);
    uint8_t running = 1;

    //shape test for rect
    SofaShape sofashape;

    double shape_test[8] = {20, 20, 2, 2, 30, 30, 6, 4};

    sofashape.shape = &shape_test;
    sofashape.size = 8;
    sofashape.f = Rect;

    double line_test[8] = {20, 20, 40, 40, 60, 60, 80, 80};

    SofaShape sofashape2;

    sofashape2.shape = &line_test;
    sofashape2.size = 8;
    sofashape2.f = Line;

    RendererOptions r;
    r.a = 100;
    r.r = 255;
    r.b = 0;
    r.g = 0;
    for(;running;) {
        SDL_PollEvent(&e);
        SDL_RenderClear(renderer);
        RenderShape(&sofashape, window, renderer, &r);
        RenderShape(&sofashape2, window, renderer, &r);
        //printf("a");
        if(e.window.event == SDL_WINDOWEVENT_CLOSE){
            running = 0;
        }
        SDL_RenderPresent(renderer);
    }

    //SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}