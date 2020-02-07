#ifndef COW_ENGINE_HPP
#define COW_ENGINE_HPP
#include <SDL2/SDL.h>
#include "GameData.hpp"

/*

Style guide

All objects will start with capital letter
All public functions will start with a capital letter
All private functions will start with a lower case letter
The project will primarly use camel case with 1 expection.

ALl private/protected member's will begin with lower case letter
All public member's will begin with upper case letter, except for pointers
All pointers will be prefixed with p_ or P_ depending on public or private

All acronyms will be capitalized, example: RGBA

All parameters will start with lower case letter

The only use of abstract classes will be for defining interfaces
The project aims to advoid inheritence

*/

namespace cow{
    void Tick(GameData& p_gd);
    void Render(GameData& p_gd);
    void StartGame();
    void GameLoop(GameData& p_gd);
}

#endif