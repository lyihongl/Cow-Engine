#ifndef COW_WINDOW_H
#define COW_WINDOW_H
#include <SDL2/SDL.h>

typedef struct WindowManager{
    SDL_Window *window;
    SDL_Renderer *render_layer;
} WindowManager;

void WindowInit(){

}

#endif
