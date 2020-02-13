#include <SDL2/SDL.h>
#include <iostream>
#include "GameData.hpp"

namespace cow{

SDL_Keycode KeyDownEvent(GameData& p_gd) {
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0){
        switch(event.type){
            case SDL_KEYDOWN:{
                std::cout<<(SDL_GetKeyName(event.key.keysym.sym))<<std::endl;;
            }
            break;
            case SDL_QUIT:{
                p_gd.SetRunning(cow::GameData::ERunning::NO);
            }
            break;
            default:
            break;
        }
    }
}

};