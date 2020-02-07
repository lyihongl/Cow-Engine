#include <SDL2\SDL.h>
#include <iostream>
#include "../inc/Engine.hpp"
#include "../inc/GameData.hpp"

//template <typename t> struct td;

int main(int argc, char** argv) {
    //std::cout << cow::TestRectangle() << std::endl;
    cow::StartGame();
    return 0;
}

void cow::Tick(GameData& p_gd) {
}

void cow::Render(GameData& p_gd) {
}