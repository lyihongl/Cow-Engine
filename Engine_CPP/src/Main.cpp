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

void cow::Init(GameData& p_gd){
    cow::ShapeComponent s{0, cow::rect, 20, 20};
    cow::PositionComponent p{0, 100, 100};
    //p_gd.P_getEntityManager
    p_gd.P_getEntityManager()->AddShape(s);
    p_gd.P_getEntityManager()->AddPosition(p);
}