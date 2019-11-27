#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>
#include "Engine/Engine.h"

int main(int argc, char** argv){
    int x = 4;
    printf("%p\r\n", &x);
    SDL_Window *window;
    SDL_Init(SDL_INIT_EVERYTHING);
    //SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(
        "An SDL2 window",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );
    if (window == NULL) {
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Event e;
    Uint32 windowID = SDL_GetWindowID(window);
    uint8_t running = 1;
    for(;running;) {
        SDL_PollEvent(&e);
        //printf("%d\r\n", e.window.event);
        if(e.window.event == SDL_WINDOWEVENT_CLOSE){
            running = 0;
        }
        //printf("%d\r\n", SDL_WINDOWEVENT_CLOSE);
        //if(e.type == 256){
        //    running = 0;
        //}
    }

    //SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();
    return 0;
}