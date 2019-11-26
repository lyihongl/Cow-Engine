#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

int main(int argc, char** argv){
    printf("TEst");
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
      printf("oops\n\r");
    }
    return 0;
}