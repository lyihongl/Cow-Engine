#ifndef COW_INPUT
#define COW_INPUT
#include <SDL2/SDL.h>
#include <iostream>
#include "GameData.hpp"

namespace cow{
namespace HeaderLibs{
void KeyDownEvent(GameData& p_gd, bool keyArray[4]) {
    SDL_Event event;
    const Uint8 *keystate = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&event) != 0){

            //std::cout<<(SDL_GetKeyName(event.key.keysym.sym))<<std::endl;;
            keyArray[0] = keystate[SDL_SCANCODE_W];
            keyArray[1] = keystate[SDL_SCANCODE_A];
            keyArray[2] = keystate[SDL_SCANCODE_S];
            keyArray[3] = keystate[SDL_SCANCODE_S];
        //if(event.type == SDL_KEYUP){
        //    if(keystate[SDL_SCANCODE_W]){
        //        keyArray[0] = false;
        //    }
        //    if(keystate[SDL_SCANCODE_A]){
        //        keyArray[1] = false;
        //    }
        //    if(keystate[SDL_SCANCODE_S]){
        //        keyArray[2] = false;
        //    }
        //    if(keystate[SDL_SCANCODE_D]){
        //        keyArray[3] = false;
        //    }

        //}
        if(event.type == SDL_QUIT){
            p_gd.SetRunning(cow::GameData::ERunning::NO);
        }
        
    }
};
}

};
#endif